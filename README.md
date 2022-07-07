<h1 align=center>real-99's Suckless Terminal (st) fork.</h1>
<p align=center>Simple, suckless.</p>

`> Why this tho?`, thats the question I've asked myself for a long time, why would I create a fork of ST? Well, here's it is, since most of the available terminals like [Alacritty](https://github.com/alacritty/alacritty) or [Kitty](https://github.com/kovidgoyal/kitty) are either don't cover all the features I want, or are ***overloaded*** with features (with most of I won't use.)

This fork of ST covers all the featureset I need, while also obeying to the *somewhat* "minimal" codebase (well certainely well less than *kitty* ~~cough cough~~). Its snappy, lightweight, and functional.

Hyped up? If yes, navigate straight to the [Install section](#installation). Question about [Applied Patches?](#applied-patches) [Features?](#features), [Keybinds?](#keybinds) I've got you covered with a section for each of those!

## Installation

> **NOTE**: I don't have any other distros (nor VMs) to test which commands to run to install the required librairies. Please provide them with a pull request.

```sh

# NOTE: All of these commands need to be ran with root permissions.

# Gentoo dependency install.
emerge --ask x11-libs/libX11 x11-libs/libXft media-libs/fontconfig \
  media-libs/freetype media-libs/harfbuzz x11-libs/libXrender
emerge --ask media-fonts/jetbrains-mono # Optional, the default font.

# Install the terminal.
git clone https://github.com/real-fht/st
cd st && make install && make clean

# Enjoy.
st
```

## Gallery

<img title="Screenshot 1" alt="Screenshot 1" src="/img/st1.png">
<img title="Screenshot 2" alt="Screenshot 2" src="/img/st2.png">

## Applied Patches

All of these are **hand-patched**, no automation involved using `patch -p1 < ./path/to/diff`, enjoy them well!

- [Alpha](https://suckless.org/patches/alpha/): Make the terminal transparent (requires compositing)!
- [Anysize](https://st.suckless.org/patches/anysize/): To take the most space possible.
- [Blinking Cursor](https://st.suckless.org/patches/blinking_cursor/): Makes the cursor blink.
- [Bold is not Bright](https://st.suckless.org/patches/bold-is-not-bright/): Makes the bold colors actual **bold** and not brightened colors from the pallete.
- [Boxdraw](https://st.suckless.org/patches/boxdraw): Render box characters correctly.
- [Clipboard](https://st.suckless.org/patches/clipboard/): Copy and paste from global clipboard (Freedesktop Standard)
- [Desktop Entry](https://st.suckless.org/patches/desktopentry/): Create a nifty desktop entry for some app launchers and panels.
- [Font2](https://st.suckless.org/patches/font2/): Set fallback fonts in case the 1st one don't cover all the symbols.
- [Fullscreen](https://st.suckless.org/patches/fullscreen/): EWMH standard fullscreen support
- [Ligatures](https://st.suckless.org/patches/ligatures/): Fancy ligatures support (if your font supports it)
- [New term](https://st.suckless.org/patches/newterm/): Open a new ST window in the same current working directory.
- [Patch column](https://github.com/nimaipatel/st/blob/master/patches/7672445bab01cb4e861651dc540566ac22e25812.diff): Avoid text cutting while resizing.
- [Scrollback](https://st.suckless.org/patches/scrollback/): Scrollback support for ST + [Scrollback Mouse](https://st.suckless.org/patches/scrollback/st-scrollback-mouse-20220127-2c5edf2.diff) to scrollback with Shift+Mousewheel.
- [Undercurl](https://st.suckless.org/patches/undercurl/): Undercurl support for ST. (Supports different styles!)

### Acknowledgements.

This project have inspiration, or took ideas, code, and more from the following:

- [Suckless developers](https://suckless.org): for their amazing work on their projects such as [st](https://st.suckless.org).
- Other ST forks out there: [Luke Smith's ST](https://github.com/lukesmithxyz/st), [Siduck's Snazzy Terminal](https://github.com/siduck/st/), and other forks I don't remember.
