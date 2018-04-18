# blowbox-2018
Blowbox is my pet/hobby project. I've started building game engines back in 2015 ([blowbox-2015](https://github.com/RikoOphorst/blowbox-2015)) and this repo is the fourth iteration of the ongoing Blowbox game project. Feature set is... pretty much undefined. I make whatever I feel like making for the engine, but the aim is always to have a game engine that can be used to make games with.

## Cloning the repo
When you want to clone the repo, make sure to also recursively retrieve the project's submodules. An example way of doing this from Git Bash:

`git clone --recurse-submodules https://github.com/RikoOphorst/blowbox-2018.git` 

## Dependencies
Blowbox 2018 consists of a lot of varying dependencies, ranging from IDEs, to platforms, to compilers, to libraries, etc.

### Windows
Blowbox has only been tested on Windows 10 and no older or newer versions. The Windows SDK version that is used is **10.0.16299.0**.

### CMake
The project is *entirely* configured using **CMake 3.11.0**. It has not been tested with newer versions of CMake. Download CMake over at [their official website](https://cmake.org/).

### Visual Studio
Blowbox has only been tested with **Visual Studio 2017** with the specific version being **15.6.4**. The platform toolset used is **Visual Studio 2017 (v141)**.

### Qt
The Blowbox Editor depends on **Qt 5.10.1**, specifically their msvc2017 64 bit exes/libs/dlls. This is configurable in the Qt installer, downloadable at [their website](https://www.qt.io/).

### LuaJIT
Although this is a submodule of the project, I'd like to state that you still **need to build LuaJIT yourself**. This is because LuaJIT does not have CMake support and must therefore be linked directly. To do that, you need to open some sort of Visual Studio Developer Command Prompt in 64 bit mode. With Visual Studio 2017 & Windows 10, you can open the start menu, look for the "Visual Studio 2017" folder in the start menu, open that, and open the *x64 Native Tools Command Prompt for VS 2017*. Inside of that command prompt, navigate to `<pathtoyourblowboxclonelocation>/deps/luajit/src/` in which you can then run the `msvcbuild.bat`. This will then automatically compile LuaJIT into the correct location so you never have to worry about it again. For posterity's sake, Blowbox uses **LuaJIT v2.0.5** which was originally downloadable through their [website](http://luajit.org/) and [their own git repo](http://luajit.org/git/luajit-2.0.git).

### Assimp
Blowbox also uses **Assimp 4.1.0** for asset processing, however this is submoduled and added to the CMake configuration automatically, so you don't need to worry about this.

### GLFW
For Input handling & Window creation, blowbox uses **GLFW 3.2.1**. This is also submoduled, so no need to worry again about this.

### GLM
Math in blowbox is handled by **GLM 0.9.8.5**, but again this is a submodule == no worries for you.

### EASTL
Blowbox relies on **EASTL 3.09.00** for fast, optimized data structures and containers, but guess what? It's a submodule.

###
