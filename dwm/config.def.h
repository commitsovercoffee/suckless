/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 7;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const unsigned int systraypinning = 0;   /* 0: sloppy systray follows selected monitor, >0: pin systray to monitor X */
static const unsigned int systrayonleft = 0;    /* 0: systray in the right corner, >0: systray on left of status text */
static const unsigned int systrayspacing = 2;   /* systray spacing */
static const int systraypinningfailfirst = 1;   /* 1: if pinning fails, display systray on the first monitor, False: display systray on the last monitor*/
static const int showsystray        = 1;        /* 0 means no systray */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char *fonts[]          = { "FiraCode Nerd Font Mono:size=14" };
static const char dmenufont[]       = "FiraCode Nerd Font Mono:size=14";
static const char col_gray1[]       = "#222222";
static const char col_gray2[]       = "#444444";
static const char col_gray3[]       = "#bbbbbb";
static const char col_gray4[]       = "#eeeeee";
static const char col_cyan[]        = "#31353D";
static const char *colors[][3]      = {
    /*               fg         bg         border   */
    [SchemeNorm] = { col_gray3, col_gray1, col_gray1 },
    [SchemeSel]  = { col_gray4, col_cyan,  col_gray3 },
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

static const unsigned int ulinepad	= 5;	/* horizontal padding between the underline and tag */
static const unsigned int ulinestroke	= 2;	/* thickness / height of the underline */
static const unsigned int ulinevoffset	= 0;	/* how far above the bottom of the bar the line should appear */
static const int ulineall 		= 0;	/* 1 to show underline on all tags, 0 for just the active ones */

static const Rule rules[] = {

    /* class    instance    title   tags-mask   isfloating   monitor */

    // tag 0 : current
    { "Gcolor3",            NULL,   NULL,   0,  1,  -1 }, // colorpicker
    { "Gnome-screenshot",   NULL,   NULL,   0,  1,  -1 }, // screencap as image
    { "Peek",               NULL,   NULL,   0,  1,  -1 }, // screencap as GIF
    { "Ristretto",          NULL,   NULL,   0,  1,  -1 }, // screencap as GIF

    // tag 1 : browser
    { "firefox",            NULL,   NULL,   1,  0,  -1 },
    { "Tor Browser",        NULL,   NULL,   1,  0,  -1 },

    // tag 2 : terminal
    { "st-256color",        NULL,   NULL,   1 << 1,  0,  -1 },

    // tag 3 : work
    { "Vivaldi-stable",     NULL,   NULL,   1 << 2,  0,  -1 },

    // tag 4 : docs
    { "Evince",             NULL,   NULL,   1 << 3,  0,  -1 },
    { "Gedit",              NULL,   NULL,   1 << 3,  0,  -1 },
    { "libreoffice",        NULL,   NULL,   1 << 3,  0,  -1 },

    // tag 5 : utils
    { "Pavucontrol",        NULL,   NULL,   1 << 4,  0,  -1 },
    { "Blueman-manager",    NULL,   NULL,   1 << 4,  0,  -1 },
    { "qBittorrent",        NULL,   NULL,   1 << 4,  0,  -1 },
    { "Gnome-disks",        NULL,   NULL,   1 << 4,  0,  -1 },

    // tag 6 : files & media player
    { "Pcmanfm",            NULL,   NULL,   1 << 5,  0,  -1 },
    { "mpv",                NULL,   NULL,   1 << 5,  0,  -1 },

    // tag 7 : studio
    { "obs",                NULL,   NULL,   1 << 6,  0,  -1 },
    { "Pitivi",             NULL,   NULL,   1 << 6,  0,  -1 },

    // tag 8 : creative
    { "Inkscape",           NULL,   NULL,   1 << 7,  0,  -1 },
    { "kolourpaint",        NULL,   NULL,   1 << 7,  0,  -1 },
    { "krita",              NULL,   NULL,   1 << 7,  0,  -1 },
    { "MyPaint",            NULL,   NULL,   1 << 7,  0,  -1 },

};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 2;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

#include "tcl.c"
#include "horizgrid.c"
static const Layout layouts[] = {
    /* symbol     arrange function */
    { "|||",      tcl },
    { "###",      horizgrid },

};

/* key definitions */
#define MODKEY Mod1Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_cyan, "-sf", col_gray4, NULL };
static const char *termcmd[]  = { "st", NULL };
static const char *printscr[] = {"gnome-screenshot", "-i", NULL};
static const char *gcolor[]  = {"gcolor3", NULL};
static const char *neovide[]  = {"neovide", NULL};
static const char *slock[]  = {"slock", NULL};
static const char *pcmanfm[]  = {"pcmanfm", NULL};
static const char *appfinder[]  = {"xfce4-appfinder", NULL};
static const char *volman[]   = {"pavucontrol", NULL};
static const char *blueman[]   = {"blueman-manager", NULL};
static const char scratchpadname[] = "scratchpad";
static const char *scratchpadcmd[] = { "st", "-t", scratchpadname, "-g", "120x34", NULL };

static Key keys[] = {
    /* modifier                     key        function        argument */
    { MODKEY,                       XK_d,      spawn,          {.v = appfinder } },
    { MODKEY|ShiftMask,             XK_Return, spawn,          {.v = termcmd } },
    { MODKEY,                       XK_grave,  togglescratch,  {.v = scratchpadcmd } },
    /*  { MODKEY,                       XK_b,      togglebar,      {0} },*/
    { MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
    { MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
    { MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
    { MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
    { MODKEY,                       XK_Return, zoom,           {0} },
    { MODKEY,                       XK_Tab,    view,           {0} },
    { MODKEY|ShiftMask,             XK_q,      killclient,     {0} },
    { MODKEY,                       XK_space,  setlayout,      {0} },
    { MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
    { MODKEY|ShiftMask,             XK_f,      togglefullscr,  {0} },
    { MODKEY,                       XK_0,      view,           {.ui = ~0 } },
    { MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
    { MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
    { MODKEY,                       XK_period, focusmon,       {.i = +1 } },
    { MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
    { MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
// { MODKEY|ShiftMask,             XK_h,      layoutscroll,   {.i = -1 } },
//  { MODKEY|ShiftMask,             XK_l,      layoutscroll,   {.i = +1 } },
    { MODKEY|ShiftMask,             XK_p,      spawn,          {.v = printscr } },
    { MODKEY|ShiftMask,             XK_c,      spawn,          {.v = gcolor } },
    { MODKEY|ShiftMask,             XK_l,      spawn,          {.v = slock } },
    { MODKEY|ShiftMask,             XK_k,      spawn,          {.v = pcmanfm } },
    { MODKEY|ShiftMask,             XK_v,      spawn,          {.v = volman } },
    { MODKEY|ShiftMask,             XK_b,      spawn,          {.v = blueman } },
    { MODKEY|ShiftMask,             XK_n,      spawn,          {.v = neovide } },
    TAGKEYS(                        XK_1,                      0)
    TAGKEYS(                        XK_2,                      1)
    TAGKEYS(                        XK_3,                      2)
    TAGKEYS(                        XK_4,                      3)
    TAGKEYS(                        XK_5,                      4)
    TAGKEYS(                        XK_6,                      5)
    TAGKEYS(                        XK_7,                      6)
    TAGKEYS(                        XK_8,                      7)
    TAGKEYS(                        XK_9,                      8)
    {
        MODKEY|ShiftMask,             XK_x,      quit,           {0}
    },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
    /* click                event mask      button          function        argument */
    { ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
    { ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
    { ClkWinTitle,          0,              Button2,        zoom,           {0} },
    { ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
    { ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
    { ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
    { ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
    { ClkTagBar,            0,              Button1,        view,           {0} },
    { ClkTagBar,            0,              Button3,        toggleview,     {0} },
    { ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
    { ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};
