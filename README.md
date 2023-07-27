## Getting Started

## Server

### Dependencies

First, the version `3.16^` of CMake is necessary.

Second, you'll need to get at the version `6.3^` of QtBase.

To do so, use the following commands based on those <a src="`https://wiki.qt.io/Building_Qt_6_from_Git`">instructions</a>: 

```bash
$ git clone https://github.com/qt/qtbase.git
$ git checkout v6.5.2
$ cd .. && mkdir qtbase-debug-build && cd qtbase
$ ./configure -debug -prefix ../qtbase-debug-build
$ cmake --build . --parallel 4
$ cmake --install .
```

### Build

To link the depencies together use `cmake build` and use the tools you prefere to build the executable.
