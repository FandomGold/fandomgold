##### Master Status

[![Build Status](https://travis-ci.org/ZirtysPerzys/dragonglass.svg?branch=master)](https://travis-ci.org/ZirtysPerzys/dragonglass)
<p align="right"><a href="https://fandom.gold">Website</a><p align="right">
<p align="right"><a href="https://drgl.info">ChainXplore</a><p align="right">
<p align="right"><a href="https://drgl.online">ÆJTs Pool</a><p align="right">
<p align="right"><a href="https://crypto9coin.cf/drgl">Pxckets Pool</a><p align="right">
<p align="right"><a href="https://drgl.cool-pool.net/">CoolPool</a><p align="right">
<h1 align="center"><img title="The Long Night Is Coming" src="https://avatars2.githubusercontent.com/u/55260556?s=200&v=4" width="200" height="200" ><img/></h1>

<h2 align="center"> FANDOM GOLD <h2 align="center">

<p align="center">Rare P2P Privacy Currency <p align="center">





 
 




#### Building On *nix

1. Dependencies: GCC 4.7.3 or later, CMake 2.8.6 or later, and Boost 1.55.

You may download them from:

* http://gcc.gnu.org/
* http://www.cmake.org/
* http://www.boost.org/


*** Alternatively, it may be possible to install them using a package manager by
executing the following command.
 ```
 sudo apt-get install build-essential git cmake libboost-all-dev
```

2. Clone Fandom Gold repository
```
git clone https://github.com/FandomGold/fango
```
3. Open folder with copied repository

`cd fango`

4. Building (Compiling)

*** Execute the following command to compile
`
make -j4  
`

The resulting executables can be found in build/release/src.


5. Starting fango daemon
`
cd fango/build/release/src 
`

*** Start daemon, by typing the following command-
`
./fandomgold 
`
for a list of commands in dæmon type  --help



alternatively, &/or also see the [{XGD} GUI Wallet](https://github.com/ZirtysPerzys/DRGL)


_________________________________________________________
**Advanced options:**

* Parallel build: run `make -j<number of threads>` instead of `make`.
* Debug build: run `make build-debug`.
* Test suite: run `make test-release` to run tests in addition to building. Running `make test-debug` will do the same to the debug version.
* Building with Clang: it may be possible to use Clang instead of GCC, but this may not work everywhere. To build, run `export CC=clang CXX=clang++` before running `make`.

**************************************************************************************************
### On Windows
Dependencies: MSVC 2013 or later, CMake 2.8.6 or later, and Boost 1.55. You may download them from:

* http://www.microsoft.com/
* http://www.cmake.org/
* http://www.boost.org/

To build, change to a directory where this file is located, and run these commands: 
```
mkdir build
cd build
cmake -G "Visual Studio 12 Win64" ..
```

And then do Build.
________________


*courtesy of Sir {WindowSlayer} Galapagos*


On windows 10
Quick step by step tutorial


Activate the Bash terminal as shown in this tutorial
https://www.windowscentral.com/how-install-bash-shell-command-line-windows-10


Start a Bash window and do as follow

1:Go to root
cd

2: Run updates and install dependencies
sudo apt-get update
sudo apt-get install build-essential git cmake libboost-all-dev

3: Git clone
git clone https://github.com/ZirtysPerzys/dragonglass.git

4: Build the files
cd dragonglass
make

5: Sync blocks
cd build/release/src/
./dragonglassd

!!keep this terminal running and open new terminal for next step!!

6: Start simplewallet and create wallet (navigate to the folder where you created the wallet)
~dragonglass/build/release/src$ ./simplewallet
or
cd dragonglass/build/release/src
./simplewallet

set up wallet name & password
then start mining in wallet
start_mining <number_of_threads>

use "help" in wallet to check other commands

!!Remember you have to use linux command in Bash

You'll find your folders and wallet in
C:\Users\YOURUSERNAME\AppData\Local\lxss\home

**************************************************


### Building for Android on Linux

Set up the 32 bit toolchain
Download and extract the Android SDK and NDK
```
android-ndk-r15c/build/tools/make_standalone_toolchain.py --api 21 --stl=libc++ --arch arm --install-dir /opt/android/tool32
```

Download and setup the Boost 1.65.1 source
```
wget https://sourceforge.net/projects/boost/files/boost/1.65.1/boost_1_65_1.tar.bz2/download -O boost_1_65_1.tar.bz2
tar xjf boost_1_65_1.tar.bz2
cd boost_1_65_1
./bootstrap.sh
```
apply patch from external/boost1_65_1/libs/filesystem/src

Build Boost with the 32 bit toolchain
```
export PATH=/opt/android/tool32/arm-linux-androideabi/bin:/opt/android/tool32/bin:$PATH
./b2 abi=aapcs architecture=arm binary-format=elf address-model=32 link=static runtime-link=static --with-chrono --with-date_time --with-filesystem --with-program_options --with-regex --with-serialization --with-system --with-thread --with-context --with-coroutine --with-atomic --build-dir=android32 --stagedir=android32 toolset=clang threading=multi threadapi=pthread target-os=android --reconfigure stage
```

Build {XDG} for 32 bit Android
```
mkdir -p build/release.android32
cd build/release.android32
CC=clang CXX=clang++ cmake -D BUILD_TESTS=OFF -D ARCH="armv7-a" -ldl -D STATIC=ON -D BUILD_64=OFF -D CMAKE_BUILD_TYPE=release -D ANDROID=true -D BUILD_TAG="android" -D BOOST_ROOT=/opt/android/boost_1_65_1 -D BOOST_LIBRARYDIR=/opt/android/boost_1_65_1/android32/lib -D CMAKE_POSITION_INDEPENDENT_CODE:BOOL=true -D BOOST_IGNORE_SYSTEM_PATHS_DEFAULT=ON ../..
make SimpleWallet
```
**************************************************

