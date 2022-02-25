/* appearance */
static const unsigned int borderpx = 0;
static const unsigned int snap     = 32;
static const int showbar           = 1;
static const int topbar            = 1;
static const char *fonts[]         = { "Fira code nerd font:size=8", "JoyPixels:pixelsize=16" };

#include "colors/curcol.h"

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5" };

static const Rule rules[] = { };

static const int nmaster     = 1;
static const int resizehints = 0;
static const float mfact     = 0.55;
static const int lockfullscreen = 0;

static const Layout layouts[] = {
    /* symbol     arrange function */
    { "[]=",      tile },    /* first entry is default */
    { "><>",      NULL },    /* no layout function means floating behavior */
    { "[M]",      monocle },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
    { MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
        { MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
        { MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
        { MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, NULL };
static const char *termcmd[]  = { "st", NULL };

// Volume controls
static const char *mutecmd[]  = { "vol_ctl", "mute", NULL };
static const char *volupcmd[]  = { "vol_ctl", "up", NULL };
static const char *voldowncmd[]  = { "vol_ctl", "down", NULL };

// Brightness controll
static const char *briupcmd[] = { "bri_ctl", "up", NULL };
static const char *bridowncmd[] = { "bri_ctl", "down", NULL };

// Clipmenu
static const char *clipmenucmd[] = { "clipmenu", NULL };

// Lock
static const char *lockcmd[] = { "slock", NULL };

// Screenshot
static const char *scrshot[] = { "scrshot", NULL };

// NOTE: Delete this if you don't use extra keys
#include <X11/XF86keysym.h>
static Key keys[] = {
    /* modifier         key        function        argument */
    { MODKEY,           XK_q,      killclient,     {0}        },
    { MODKEY,           XK_t,      setlayout,      {.v = &layouts[0]} },
    { MODKEY,           XK_l,      spawn,          {.v = lockcmd } },
    { MODKEY,           XK_c,      spawn,          {.v = clipmenucmd } },
    { MODKEY,           XK_d,      spawn,          {.v = dmenucmd } },
    { MODKEY,           XK_Return, spawn,          {.v = termcmd } },
    { MODKEY,           XK_b,      togglebar,      {0} },
    { MODKEY,           XK_j,      focusstack,     {.i = +1 } },
    { MODKEY,           XK_k,      focusstack,     {.i = -1 } },

    { MODKEY|ShiftMask, XK_i,      incnmaster,     {.i = -1 } },
    { MODKEY,           XK_i,      incnmaster,     {.i = +1 } },

    { MODKEY,           XK_h,      setmfact,       {.f = -0.05} },
    { MODKEY,           XK_l,      setmfact,       {.f = +0.05} },
    { MODKEY,           XK_m,      setlayout,      {.v = &layouts[2]} },
    { MODKEY,           XK_space,  setlayout,      {0} },
    { MODKEY,           XK_f,      togglefullscr,  {0} },
    { MODKEY|ShiftMask, XK_f,      zoom,           {0} },
    { MODKEY,           XK_0,      view,           {.ui = ~0} },
    { MODKEY,           XK_comma,  focusmon,       {.i = -1 } },
    { MODKEY,           XK_period, focusmon,       {.i = +1 } },
    { MODKEY|ShiftMask, XK_comma,  tagmon,         {.i = -1 } },
    { MODKEY|ShiftMask, XK_period, tagmon,         {.i = +1 } },
    { MODKEY|ShiftMask, XK_0,      tag,            {.ui = ~0 }},
    { MODKEY|ShiftMask, XK_space,  togglefloating, {0} },

    { 0, XF86XK_AudioMute,        spawn,      {.v = mutecmd}  },
    { 0, XF86XK_AudioRaiseVolume, spawn,      {.v = volupcmd} },
    { 0, XF86XK_AudioLowerVolume, spawn,      {.v = voldowncmd}},
    { 0, XF86XK_MonBrightnessUp,  spawn,      {.v = briupcmd} },
    { 0, XF86XK_MonBrightnessDown,spawn,      {.v = bridowncmd}},
    { 0, XK_Print,                spawn,      {.v = scrshot}},

    TAGKEYS(XK_1, 0)
    TAGKEYS(XK_2, 1)
    TAGKEYS(XK_3, 2)
    TAGKEYS(XK_4, 3)
    TAGKEYS(XK_5, 4)
    { MODKEY|ShiftMask, XK_q, quit, {0} },
};

static Button buttons[] = {
    { ClkLtSymbol,  0,      Button1, setlayout,      {0} }, { ClkClientWin, MODKEY, Button1, movemouse,      {0} },
    { ClkClientWin, MODKEY, Button2, togglefloating, {0} }, { ClkClientWin, MODKEY, Button3, resizemouse,    {0} },
};

