# Build

## build and install

### generate DiffAlgoEval.h file
```shell
cd $CODE_ROOT
uic DiffAlgoEval.ui -o DiffAlgoEval.h
```

### generate exe and install exe file

```shell
cd $CODE_ROOT

cmake -G "MinGW Makefiles" -DCMAKE_MAKE_PROGRAM=C:/Qt/Tools/mingw1310_64/bin/make.exe -DCMAKE_CXX_COMPILER=C:/Qt/Tools/mingw1310_64/bin/x86_64-w64-mingw32-g++.exe -DQt6_DIR=C:/Qt/6.8.2/mingw_64/lib/cmake/Qt6 -DCMAKE_INSTALL_PREFIX=C:/Users/z00509zf/DiffAlgoEval -DCMAKE_RC_COMPILER=C:/Qt/Tools/mingw1310_64/bin/windres.exe -B build

cmake --build ./build
cmake --install ./build

```

```shell
cmake --build ./build --target clean
```