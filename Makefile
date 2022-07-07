# st - simple terminal
# See LICENSE file for copyright and license details.
.POSIX:

include config.mk

SRC = st.c x.c boxdraw.c hb.c
OBJ = $(SRC:.c=.o)

all: options st

options:
	@echo st build options:
	@echo "CFLAGS  = $(STCFLAGS)"
	@echo "LDFLAGS = $(STLDFLAGS)"
	@echo "CC      = $(CC)"

.c.o:
	$(CC) $(STCFLAGS) -c $<

st.o: config.h keys.h st.h win.h
x.o: arg.h keys.h config.h st.h win.h hb.h
boxdraw.o: config.h keys.h st.h boxdraw_data.h
hb.o: st.h

$(OBJ): config.h config.mk

st: $(OBJ)
	$(CC) -o $@ $(OBJ) $(STLDFLAGS)

clean:
	rm -f st $(OBJ) st-$(VERSION).tar.gz *.{orig,rej}

dist: clean
	mkdir -p st-$(VERSION)
	cp -R Makefile README.md config.mk\
		 misc/{st.info,st.1} arg.h st.h win.h $(SRC)\
		st-$(VERSION)
	tar -cf - st-$(VERSION) | gzip > st-$(VERSION).tar.gz
	rm -rf st-$(VERSION)

install: st
	mkdir -p $(DESTDIR)$(PREFIX)/bin
	cp -f st $(DESTDIR)$(PREFIX)/bin
	chmod 755 $(DESTDIR)$(PREFIX)/bin/st
	mkdir -p $(DESTDIR)$(MANPREFIX)/man1
	sed "s/VERSION/$(VERSION)/g" < misc/st.1 > $(DESTDIR)$(MANPREFIX)/man1/st.1
	chmod 644 $(DESTDIR)$(MANPREFIX)/man1/st.1
	# Misc setup (terminfo, man page, app.)
	tic -sx misc/st.info
	@echo Please see the README file regarding the terminfo entry of st.
	mkdir -p $(DESTDIR)$(PREFIX)/share/applications
	cp -f misc/st.desktop $(DESTDIR)$(PREFIX)/share/applications
	make clean

lint: clean
	clang-format -i ./*.c ./*.h

uninstall:
	rm -f $(DESTDIR)$(PREFIX)/bin/st
	rm -f $(DESTDIR)$(MANPREFIX)/man1/st.1
	rm -f $(DESTDIR)$(PREFIX)/share/applications/st.desktop

.PHONY: all options clean dist install uninstall
