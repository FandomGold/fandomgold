   {Dragonglass} kills white walkers....
---------------------------------------

It is more valuable to us now.. than gold.

We need to find it-

We need to MINE it-

We need to MAKE weapons from it


The ONLY thing now that stands between us.. 
and the Army of the dead - 
Is one last and Final season..
        Season  8 
of   GAME OF THRONES.

It is @ that time when we shall start the trading of {DRGL} with every man, woman, and child- whilst crowning only the most rightful heir of Exchange(s).. as our 8th and Final Season arrives.
_________________________________________________

As for now, every House shall be called upon to join in alliance. We must fight together- alongside one another, to defeat our common enemy.  
Any contributions to all future {DRÆGONGLASS} developments are not only welcomed, but encouraged. There is much, still, that remains to be done...For the Night is Dark, and Full of Terrors.

This process of mining , however..
begins...Now.
__________________________________________________________________

CPU/GPU proof-of-work algorithm.

~80% of all {DRGL} is set to be mined by FINAL season's debut.

( 8000008 )  max supply (Eight million eight*)   *actual total supply [8000008.8000008]
_________________________________________________


THERE  IS  ONLY  ONE  WAR  THAT  MATTERS..

The Great War.



And it is here.
________________________________________________________________________________________________________

{DRAGONGLASS} Anonymous Encrypted Digital Currency - that kills white walkers.
Built upon Cryptonote technologies. Read Cryptonote white paper at https://cryptonote.org/whitepaper.pdf

________________________________________________________________________________________________________________


_______________________________________________________________________________________________________________
## Building {Dragonglass} 

### On *nix

1. Dependencies: GCC 4.7.3 or later, CMake 2.8.6 or later, and Boost 1.55.

You may download them from:

* http://gcc.gnu.org/
* http://www.cmake.org/
* http://www.boost.org/



*** Alternatively, it may be possible to install them using a package manager by
executing the following command.     {Tested using Ubuntu 14.04}
 ```
 sudo apt-get install build-essential git cmake libboost1.55-all-dev
```
____________________________________________________________________

2. Clone {dragonglass} repository

*** Execute the following command to copy a desired repository
```
git clone https://github.com/ZirtysPerzys/dragonglass
```


3. Open folder with copied repository

*** Execute the following command to get into the directory with copied repository

`cd dragonglass`



4. Building (Compiling)

*** Execute the following command to compile

`
make -j4  
`

The resulting executables can be found in build/release/src.


5. Starting {dragonglass} daemon
*** Execute the following command to navigate to resulting executables

`
cd dragonglass/build/release/src 
`


*** Start daemon, typing the following command-

`
./dragonglassd 
`

for a list of commands in daemon type  --help




After you are have very success!!!!

 see {DragonglassWallet} 

https://github.com/ZirtysPerzys/Dragonglasswallet


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

//courtesy of the great {WindowSlayer} aka Galapagos

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

------------------------

!!Remember you have to use linux command in Bash

You'll find your folders and wallet in
C:\Users\YOURUSERNAME\AppData\Local\lxss\home
