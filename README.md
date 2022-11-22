# std_fix
Patches for outdated-yet-latest STL implementations.

Targets like Android and iOS tie you to vendor provided C++ runtimes (which are as a rule outdated and/or come from a 'random'/not-official-release libcpp commit).

Expecting/supporting:
 - Apple: Xcode 14
 - Android: NDK 25b
 - Emscripten: emsdk 3.1.17
 - Linux: LLVM15
 - Windows: LLVM15 w/ Clang-CL