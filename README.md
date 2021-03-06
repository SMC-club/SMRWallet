# SMRWallet
Lightweight wallet for SMR with Qt based interface 
Only 64-bit operation systems are supported.

## Build instructions

### Windows
1. Install Visual Studio Community 2017 with C++ and Windows SDK.
2. Setup Git for Windows.
2. Download the dependency archive and unpack it to C:\MyProjects\ directory.
3. Run qmake_env_static.cmd and use opened command prompt for the next actions.
3. Clone this repository:
    git clone http://github.com/RussianMiningCoin/SMRWallet
4. Open x64 Visual Studio 2017 Native CMD
5. Prepare paths for qmake-static, boost_1.68, use vcpkg to install static libs of protobuf openssl and zlib
6. Run the following commands:
```
    call "C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\VC\Auxiliary\Build\vcvars64.bat"
    set PATH=%PATH%C:\MyProjects\deps\qt-static\bin;C:\MyProjects;
    set LIBPATH=%LIBPATH%C:\local\boost_1_68_0\lib;
    set INCLUDE=%INCLUDE%C:\local\boost_1_68_0;
    set LIBPATH=%LIBPATH%C:\MyProjects\deps\qt-static\lib;
    set INCLUDE=%INCLUDE%C:\MyProjects\deps\qt-static\include;
    set QTDIR=C:\MyProjects\deps\qt-static
    set OPENSSL_ROOT_DIR=C:\vcpkg\installed\x64-windows-static
    set BOOST_ROOT=C:\local\boost_1_68_0


    cd SMRWallet
    C:\MyProjects\deps\qt-static\bin\qmake ..
    nmake /f Makefile.Release
    mkdir build
    cd build && qmake ..
    nmake
```    
5. You're done ;)

### Mac OS X
1. Install Apple XCode and setup Homebrew
2. Download Qt for Mac OS  from the official site and setup it as usual.
3. Install the following Homebrew packages:
    brew install boost openssl cmake protobuf scons
4. Clone and build ripple-libpp:
```
    git clone https://github.com/RussianMiningCoin/smr-libpp
    cd smr-libpp && git update submodule --init --recursive
    mkdir build && cd build
    cmake .. && make
    cd ../..
```
5. Clone this repository and open SMRWallet.pro in Qt Creator.
6. You should be able to build your project as usual. If it doesn't work then ensure that smr-libpp tree is sharing parent directory with SMRWallet project.

### Other NIXes
Should be similar to OS X steps. You may also need to build boost 1.66 though. Please consider reading smr-libpp build instructions first.

## Build dependencies

Windows x64 dependencies:

https://drive.google.com/file/d/1uLYJ-9I3NuZz5amsHD1rxMEacVim4weC/view?usp=sharing

These builds were made with MT Release configuration using Visual Studio 2017.
