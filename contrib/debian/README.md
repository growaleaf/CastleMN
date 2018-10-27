
Debian
====================
This directory contains files used to package castled/castle-qt
for Debian-based Linux systems. If you compile castled/castle-qt yourself, there are some useful files here.

## castle: URI support ##


castle-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install castle-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your castleqt binary to `/usr/bin`
and the `../../share/pixmaps/castle128.png` to `/usr/share/pixmaps`

castle-qt.protocol (KDE)

