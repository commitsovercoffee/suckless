# Suckless

[suckless](https://suckless.org/) software with pre-applied patches, custom keybindings etc.

> Note : I am not the author of dwn, dmenu or any other suckless software.

## Simple Terminal

[Simple terminal](https://st.suckless.org/), otherwise known as _st_ is the terminal emulator of my choice. I have below patches installed :

- [Gruvbox](https://st.suckless.org/patches/gruvbox/) colorscheme, to go with my neovim setup.
- [Newterm](https://st.suckless.org/patches/newterm/), which allows spawning a new terminal using `Ctrl+Shift+Return` in the same CWD as the original st instance.
- [Scrollback](https://st.suckless.org/patches/scrollback/) Scroll back through terminal output using `Shift+PageUp/PageDown`.

## Dynamic Window Manager

[ Dynamic window manager](https://dwm.suckless.org/), otherwise known as _dwm_ is my go to window manager with following patches applied :

- [underlinetags](https://dwm.suckless.org/patches/underlinetags/) to highlight current tag/workspace.
- [actualfullscreen](https://dwm.suckless.org/patches/actualfullscreen/) to fullscreen apps.
- [alwayscenter](https://dwm.suckless.org/patches/alwayscenter/) to center floating apps.
- [layoutscroll](https://dwm.suckless.org/patches/layoutscroll/) to cycle through all layouts.
- [pertag](https://dwm.suckless.org/patches/pertag/) to preserve layout of each tag/workspace.
- [systray](https://dwm.suckless.org/patches/systray/) for system tray icons.
- [warp](https://dwm.suckless.org/patches/warp/) to warp the mouse cursor to the center of the currently focused window/screen.
- [scratchpad](https://dwm.suckless.org/patches/scratchpad/) to spawn or restore a floating terminal window.
- And my favorite window layouts, [three-column](https://dwm.suckless.org/patches/three-column/) and [horizgrid](https://dwm.suckless.org/patches/horizgrid/).

## Dmenu

[ Dmenu ](https://tools.suckless.org/dmenu/) is my favorite app launcher. I have patched it with :

- [center](https://tools.suckless.org/dmenu/patches/center/) ~ centers dmenu in the middle of the screen.
- [border](https://tools.suckless.org/dmenu/patches/border/) ~ adds a border around the dmenu window.
- [highlight](https://tools.suckless.org/dmenu/patches/highlight/) ~ highlights the individual characters of matched text for each dmenu list entry.
- [mouse-support](https://tools.suckless.org/dmenu/patches/mouse-support/) ~ adds basic mouse support.
