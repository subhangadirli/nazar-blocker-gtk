## Nazar Blocker GTK

Protect your computer from nazar.

For the QT one: [https://github.com/subhangadirli/nazar-blocker-gtk](https://github.com/sulincix-other/nazar-blocker)


![](nazar-blocker.png)
## Prerequisites
- GTK 3 development headers (`libgtk-3-dev`)
- libayatana-appindicator3 development headers (`libayatana-appindicator3-dev`)
- Meson build system and Ninja
- C compiler (gcc/clang)

```sh
# Ubuntu/Debian
sudo apt install libgtk-3-dev libayatana-appindicator3-dev meson ninja-build
```

## Build from source
1. Open a terminal in the project root.
2. Run:
```sh
meson setup builddir
cd builddir && ninja
```

## Install
```sh
sudo ninja install
sudo gtk-update-icon-cache /usr/share/icons/hicolor
```

## Run
- After installing:
```sh
nazar
```
- From the build directory (without install):
```sh
./builddir/nazar
```
