# QEMU README

This is a personal repo hosting Qemu with some custom patches, please refer to the original repo : [Official Qemu repo](https://gitlab.com/qemu-project/qemu)

## Prerequisites
Necessary libraries :
```
pacman -S base-devel mingw-w64-x86_64-toolchain git python ninja
pacman -S mingw-w64-x86_64-gtk3 mingw-w64-x86_64-SDL2 mingw-w64-x86_64-libslirp
pacman -S base-devel mingw-w64-x86_64-toolchain git python ninja
pacman -S mingw-w64-x86_64-glib2 mingw-w64-x86_64-pixman python-setuptools
pacman -S mingw-w64-x86_64-spice-protocol
pacman -S mingw-w64-x86_64-cmake
pacman -S mingw-w64-x86_64-spice
```

## Installation
Build command :
```
./configure --enable-sdl --enable-gtk --enable-whpx --enable-opengl --target-list=x86_64-softmmu --enable-avx2 --enable-gtk-clipboard --enable-spice-protocol --enable-spice --enable-avx512bw --enable-dsound && make
```
