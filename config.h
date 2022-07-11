/* config.h -*- configure real's ST fork. Have fun with the comments, I guess. */
// vim: nofoldenable

/* Main font to use. (see font2 for fallback fonts) */
static char *font = "Spacemono:size=12:antialias=true:autohint=true";

/* Fallback fonts, in case the main one doesn't cover all the needed characters.
 * WARN: If you don't set fallback fonts for Japanese/Chinese/Arabic/CJK/... fonts and try to render
 * one, st will crash since there's no font that could have the said character. */
static char *font2[] = {
    // "codicon:size=12:antialias:true:autohint:true",
    "Spacemono Nerd Font:size=12:antialias=true:autohint=true"
};

/* Character kerning, (basically the allowed space for a character)
 * You can consider cwscale as the character width, and chscale as the line height. */
static float cwscale = 1.0;
static float chscale = 1.0;

/* Amount of leftover space around the screen's borders. (Padding if you want) */
static int borderpx = 6;

/* ST, by default, will use the shell specified in /etc/passwd for the current user.
 * If the shell is not set there, ST will fallback to this shell. */
static char *shell = "/bin/sh";

/* Still need to command, but check https://tools.suckless.org/utmp/ */
char *utmp = NULL;

/* (Useless), let you set a scroll program, like https://tools.suckless.org/scroll/ */
char *scroll = NULL;

/* Custom some aspects of the virtual shell. */
char *stty_args = "stty tabs raw pass8 nl -echo -iexten -cstopb 38400";

/* Identification sequence returned in DA and DECID */
char *vtiden = "\033[?6c";

/* What should delimit a word from another? */
wchar_t *worddelimiters = L" `'\"()[]{}.?!\\/";

/* Allow alternative screens? */
int allowaltscreen = 1;

/* Prohibit non-interactive (insecure) actions like setting the clipboard text. */
int allowwindowops = 0;

/* Set the bell sound (between -100 and 100), bellvolume=0 means disabled. */
static int bellvolume = 0;

/* default $TERM value, don't change, else multi-color/truecolor/24bit color support will fail */
char *termname = "st-256color";

/* Number of spaces used per-tab */
unsigned int tabspaces = 2;

/* Enable/Disable ligature support */
static int enable_ligatures = 0;

/*
 * 1: render most of the lines/blocks characters without using the font for
 *    perfect alignment between cells (U2500 - U259F except dashes/diagonals).
 *    Bold affects lines thickness if boxdraw_bold is not 0. Italic is ignored.
 * 0: disable (render all U25XX glyphs normally from the font).
 */
const int boxdraw = 1;
const int boxdraw_bold = 1;

/* braille (U28XX):  1: render as adjacent "pixels",  0: use font */
const int boxdraw_braille = 1;

/* Selection timeouts (in milliseconds) */
static unsigned int doubleclicktimeout = 300;
static unsigned int tripleclicktimeout = 600;
 
/*
 * draw latency range in ms - from new content/keypress/etc until drawing.
 * within this range, st draws when content stops arriving (idle). mostly it's
 * near minlatency, but it waits longer for slow updates to avoid partial draw.
 * low minlatency will tear/flicker more, as it can "detect" idle too early.
 */
static double minlatency = 8;
static double maxlatency = 33;

/* Terminal colors. */
#include "theme.h"
static const char *colorname[] = {
    COLORS, BRIGHT_COLORS,

    [255] = 0,

    BACKGROUND_COLOR,
    FOREGROUND_COLOR,
    CURSOR_COLOR,
    REV_CURSOR_COLOR,
};

/* bg opacity */
float alpha = 1;


/* Default colors (colorname index)
 * foreground, background, cursor, reverse cursor */
unsigned int defaultbg = 256;
unsigned int defaultfg = 257;
unsigned int defaultcs = 258;
static unsigned int defaultrcs = 259;

/* Cursor style configuration.
 * Default style of cursor
 * 0: blinking block
 * 1: blinking block (default)
 * 2: steady block ("â–ˆ")
 * 3: blinking underline
 * 4: steady underline ("_")
 * 5: blinking bar
 * 6: steady bar ("|")
 * 7: blinking st cursor
 * 8: steady st cursor
 */
static unsigned int blinktimeout = 800; /* Blinking timeout for the cursor. */
static unsigned int cursorthickness = 1;
static unsigned int cursorstyle = 5;
static Rune stcursor = 0x2603; /* snowman ("â˜ƒ") */

/* Default columns and rows numbers */
static unsigned int cols = 80;
static unsigned int rows = 24;

/* Default colour and shape of the mouse cursor */
static unsigned int mouseshape = XC_xterm;
static unsigned int mousefg = 7;
static unsigned int mousebg = 0;

/* Color used to display font attributes when fontconfig selected a font which
 * doesn't match the ones requested. */
static unsigned int defaultattr = 11;

/* Printable characters in ASCII, used to estimate the advance width
 * of single wide characters. */
static char ascii_printable[] = " !\"#$%&'()*+,-./0123456789:;<=>?"
                                "@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_"
                                "`abcdefghijklmnopqrstuvwxyz{|}~";

/* Undercurl styles, they are the following:
 * 0 -> Curly.
 * 1 -> Spiky.
 * 3 -> Capped.
 */
#define UNDERCURL_STYLE 0

/* Force mouse select/shortcuts while mask is active (when MODE_MOUSE is set).
 * Note that if you want to use ShiftMask with selmasks, set this to an other
 * modifier, set to 0 to not use it. */
static uint forcemousemod = ShiftMask;

/* Internal mouse shortcuts.
 * NOTE: Don't override Button1 else selection capability will be disabled. */
static MouseShortcut mshortcuts[] = {
    /* mask                 button   function        argument       release */
    {XK_NO_MOD, Button4, kscrollup, {.i = 1}},
    {XK_NO_MOD, Button5, kscrolldown, {.i = 1}},
    {XK_ANY_MOD, Button2, selpaste, {.i = 0}, 1},
    {ShiftMask, Button4, ttysend, {.s = "\033[5;2~"}},
    {XK_ANY_MOD, Button4, ttysend, {.s = "\031"}},
    {ShiftMask, Button5, ttysend, {.s = "\033[6;2~"}},
    {XK_ANY_MOD, Button5, ttysend, {.s = "\005"}},
};

/* Internal keyboard shortcuts. */
#define MODKEY Mod1Mask
#define TERMMOD (Mod1Mask | ShiftMask)

static Shortcut shortcuts[] = {
    /* mask                 keysym          function        argument */
    {XK_ANY_MOD, XK_Break, sendbreak, {.i = 0}},
    /* ST's printer keymaps. */
    {ControlMask, XK_Print, toggleprinter, {.i = 0}},
    {ShiftMask, XK_Print, printscreen, {.i = 0}},
    {XK_ANY_MOD, XK_Print, printsel, {.i = 0}},
    /* FIXME: Zooming in and out */
    {TERMMOD, XK_J, zoom, {.f = +1}},
    {TERMMOD, XK_K, zoom, {.f = -1}},
    {TERMMOD, XK_Home, zoomreset, {.f = 0}},
    /* Copy and pasting (clipboard patch) */
    {TERMMOD, XK_C, clipcopy, {.i = 0}},
    {TERMMOD, XK_V, clippaste, {.i = 0}},
    {TERMMOD, XK_Y, selpaste, {.i = 0}},        /* Paste to the stdin from the current selection. */
    {ShiftMask, XK_Insert, selpaste, {.i = 0}}, /* Same as ^ */
    {TERMMOD, XK_Num_Lock, numlock, {.i = 0}},
    /* EWMH Fullscreen support */
    {XK_NO_MOD, XK_F11, fullscreen, {.i = 0}},
    {MODKEY, XK_Return, fullscreen, {.i = 0}}, /* Set fullscreen ala-xterm */
    {TERMMOD, XK_Return, newterm, {.i = 0}},   /* Create a new terminal in the same CWD */
    /* Scroll patch. */
    {MODKEY, XK_u, kscrollup, {.i = -1}},
    {MODKEY, XK_d, kscrolldown, {.i = -1}},
    {MODKEY, XK_k, kscrollup, {.i = 3}},
    {MODKEY, XK_j, kscrolldown, {.i = 3}},
};

/*
 * Xresources preferences to load at startup
 */
ResourcePref resources[] = {
		{ "font",         STRING,  &font },
		{ "color0",       STRING,  &colorname[0] },
		{ "color1",       STRING,  &colorname[1] },
		{ "color2",       STRING,  &colorname[2] },
		{ "color3",       STRING,  &colorname[3] },
		{ "color4",       STRING,  &colorname[4] },
		{ "color5",       STRING,  &colorname[5] },
		{ "color6",       STRING,  &colorname[6] },
		{ "color7",       STRING,  &colorname[7] },
		{ "color8",       STRING,  &colorname[8] },
		{ "color9",       STRING,  &colorname[9] },
		{ "color10",      STRING,  &colorname[10] },
		{ "color11",      STRING,  &colorname[11] },
		{ "color12",      STRING,  &colorname[12] },
		{ "color13",      STRING,  &colorname[13] },
		{ "color14",      STRING,  &colorname[14] },
		{ "color15",      STRING,  &colorname[15] },
		{ "background",   STRING,  &colorname[256] },
		{ "foreground",   STRING,  &colorname[257] },
		{ "cursorColor",  STRING,  &colorname[258] },
		{ "termname",     STRING,  &termname },
		{ "shell",        STRING,  &shell },
		{ "blinktimeout", INTEGER, &blinktimeout },
		{ "bellvolume",   INTEGER, &bellvolume },
		{ "tabspaces",    INTEGER, &tabspaces },
		{ "cwscale",      FLOAT,   &cwscale },
		{ "chscale",      FLOAT,   &chscale },
};

/*
 * Special keys (change & recompile st.info accordingly)
 *
 * Mask value:
 * * Use XK_ANY_MOD to match the key no matter modifiers state
 * * Use XK_NO_MOD to match the key alone (no modifiers)
 * appkey value:
 * * 0: no value
 * * > 0: keypad application mode enabled
 * *   = 2: term.numlock = 1
 * * < 0: keypad application mode disabled
 * appcursor value:
 * * 0: no value
 * * > 0: cursor application mode enabled
 * * < 0: cursor application mode disabled
 *
 * Be careful with the order of the definitions because st searches in
 * this table sequentially, so any XK_ANY_MOD must be in the last
 * position for a key.
 */

/*
 * If you want keys other than the X11 function keys (0xFD00 - 0xFFFF)
 * to be mapped below, add them to this array.
 */
static KeySym mappedkeys[] = {-1};

/*
 * State bits to ignore when matching key or button events.  By default,
 * numlock (Mod2Mask) and keyboard layout (XK_SWITCH_MOD) are ignored.
 */
static uint ignoremod = Mod2Mask | XK_SWITCH_MOD;
