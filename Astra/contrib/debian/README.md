
Debian
====================
This directory contains files used to package Astrad/Astra-qt
for Debian-based Linux systems. If you compile Astrad/Astra-qt yourself, there are some useful files here.

## Astra: URI support ##


Astra-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install Astra-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your Astraqt binary to `/usr/bin`
and the `../../share/pixmaps/Astra128.png` to `/usr/share/pixmaps`

Astra-qt.protocol (KDE)

