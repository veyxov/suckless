static int instant = 1;
static int topbar = 1;                      /* -b  option; if 0, dmenu appears at bottom     */
/* -fn option overrides fonts[0]; default X11 font or font set */
static const char *fonts[]          = {
    "Fira code nerd font:size=8",
    "JoyPixels:pixelsize=10"
};

static const char *prompt      = NULL;      /* -p  option; prompt to the left of input field */

#include "colors/curcol.h"

/* -l option; if nonzero, dmenu uses vertical list with given number of lines */
static unsigned int lines      = 0;

static const char worddelimiters[] = " ";
