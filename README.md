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

### Filesystem
Another dependency Blowbox is using is **Filesystem**. This is a small library for handling & resolving file paths. It doesn't have version numbers, but you can checkout the repo [here](https://github.com/wjakob/filesystem/tree/0a539a6c988dc8691af317e077893e831dee2908). 

## Generating the project with CMake
If you've cloned the repo, made sure to get all submodules and gotten all the standalone dependencies & built, you can generate the project using CMake. I always do this with CMake-GUI.

As the source folder, input the location where you cloned the source of blowbox 2018.
As the binary folder: I always use a folder just inside of my source project called "bin". This is where your .sln files will go and all the generated exe's, libs & dlls. This "bin" folder is also ignored using this project's .gitignore. Optionally you can also specify any other folder on your machine - it doesn't really matter.

You **must** add a path-variable to your CMake cache called `CMAKE_PREFIX_PATH`. The path you should enter here is the path to wherever you installed Qt on your machine. The path will look something like this: `<pathtoqtinstallation>/5.10.1/msvc2017_64`. This is necessary for CMake to find the Qt installation.

Once you've done that, hit Configure, then Generate and then Open. In the Configure step, make sure to use "Visual Studio 15 2017 Win64". No other IDE's have been tested, so uhm, have fun with choosing different ones. 

## Blowbox 2018 Architecture
Blowbox 2018 consists of a few different projects that together make up the entire engine.

### blowbox-core
This is the "core" part of the engine and depends on no other projects in the solution. Things like memory management, logging and other core parts of the engine are situated in this project. Blowbox-core is built as a static library.

### blowbox-graphics
This is the part of the engine that manages everything related to getting pixels to appear on your screen. This project only depends on blowbox-core. Blowbox-graphics is built as a static library.

### blowbox-scripting
Blowbox-scripting handles all things related to scripting with LuaJIT. This project only depends on blowbox-core. Blowbox-scripting is built as a static library.

### blowbox-builder
Blowbox-builder manages everything for processing assets. This project only depends on blowbox-core. Blowbox-builder is built as a static library.

### blowbox-engine
Blowbox-engine mixes the various subprojects into one. Stuff like the game loop, services, etc all get handled and controlled from the blowbox-engine. The project depends on blowbox-core, blowbox-graphics, blowbox-scripting and blowbox-builder. It is built as a static library.

### blowbox-client
Blowbox-client is a layer on top of the blowbox-engine and functions as the executable that can run games. It depends obviously on blowbox-engine and is obviously built as an executable.

### blowbox-editor
This is also a layer on top of the engine, however this also includes the entire editor suite built with Qt. Obviously it depends on blowbox-engine and is obviously built as an executable.

