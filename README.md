<img title="Unlock the Power of Fandom" src="https://raw.githubusercontent.com/FandomGold/XFG-data/master/Fango_gif01.GIF"><img/>
### Fango is an open-source decentralized P2P privacy cryptocurrency network built by sound money advocates and fandom enthusiasts.

Based on the CryptoNote protocol & philosophy.

* <p align="left"><a href="https://fandomgold.org">Website</a><p align="left">
* <p align="left"><a href="http://explorer.fandom.gold">Explorer</a><p align="left">
* <p align="left"><a href="http://xfg.dedaloproduction.ch/#">Explorer</a><p align="left">
 

 ______________________________
 


##### Master Status   

[![Build Status](https://travis-ci.org/FandomGold/fandomgold.svg?branch=master)](https://travis-ci.org/FandomGold/fandomgold) 

<sup>"Working software is the primary measure of progress." [‣]</sup>


[‣]:http://agilemanifesto.org/

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

2. Clone Fango repository
```
git clone https://github.com/FandomGold/fango

```
3. Open folder with copied repository
```
cd fango
```
4. Building (Compiling)
    (resulting programs will be found in build/release/src)

```
make -j4
```

5. Starting Fango daemon
```
cd fango/build/release/src `
./fangod
````
try --help from within dæmon for a full list of available commands
or <code>./fangod --help</code> when outside of dæmon 
_________________________________________________________
For the most user-friendly graphical interface experience

see [Fango Desktop Wallet](https://github.com/fandomgold/fango-wallet). 
_________________________________________________________

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

****Quick step by step tutorial using a Bash terminal on Windows 10****

*(courtesy of & gratitude to Sir Galapagos aka WindowSlayer)*

https://www.windowscentral.com/how-install-bash-shell-command-line-windows-10

Start a Bash window and do as follows

1:Go to root
```
cd
```
2: Run updates and install dependencies
```
sudo apt-get update
sudo apt-get install build-essential git cmake libboost-all-dev
```
3: Grab the Fango files from Github repository
```
git clone https://github.com/FandomGold/fango.git
```
4: Build the files
```
cd fango
make
```
5: Start client and begin syncing blockchain
```
cd build/release/src/
./fangod
```
*!!keep this terminal running and open new terminal for next step!!*

6: Start simplewallet and create your new wallet (navigate to the folder where you created the wallet)
```
~fango/build/release/src$ ./simplewallet
```
or
```
cd fango/build/release/src
./simplewallet
```
set up your wallet name & password

then use "help" in wallet for a list of all available commands

*!!Remember you have to use linux command in Bash*

You'll find your folders and wallet in
C:\Users\YOURUSERNAME\AppData\Local\lxss\home

**************************************************

### Build for Android on Linux

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

Build fango for 32 bit Android
```
mkdir -p build/release.android32
cd build/release.android32
CC=clang CXX=clang++ cmake -D BUILD_TESTS=OFF -D ARCH="armv7-a" -ldl -D STATIC=ON -D BUILD_64=OFF -D CMAKE_BUILD_TYPE=release -D ANDROID=true -D BUILD_TAG="android" -D BOOST_ROOT=/opt/android/boost_1_65_1 -D BOOST_LIBRARYDIR=/opt/android/boost_1_65_1/android32/lib -D CMAKE_POSITION_INDEPENDENT_CODE:BOOL=true -D BOOST_IGNORE_SYSTEM_PATHS_DEFAULT=ON ../..
make SimpleWallet
```
**************************************************
