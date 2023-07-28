## Getting Started

## Server

### List of dependencies

Cmake `3.16^` 

The Qt6 library with only the following submodules:
* qtbase
* qthttpserver

To do so, here's a script to install qt properly

```bash
$ git clone https://code.qt.io/qt/qt5.git qt6
$ git switch v6.6
$ cd .. && mkdir qt6-debug-build && cd qt6
$ ./init-repository --module-subset=qtbase,qthttpserver
$ ./configure -debug -prefix ../qt6-debug-build
$ cmake --build . --parallel 4
$ cmake --install .
```

Once that this is done, change the path `CMAKE_PREFIX_PATH` inside the top level CMakeLists.txt file to your `qt6-debug-build` path.

### Build

To link the depencies together use `cmake build` and use the tools you prefere to build the executable.
