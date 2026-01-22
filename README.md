# **Programming Abstractions in C++**

[Stanford CS106B Programming Abstractions](https://web.stanford.edu/class/cs106b/)

[Amazon.com: Programming Abstractions in C++](https://www.amazon.com/Programming-Abstractions-C-Eric-Roberts/dp/0133454843)

[Companion Website -&gt; Student Resources](https://media.pearsoncmg.com/ph/wps-wraps/ecs_roberts_pacpp/cw/#student-resources)

---

## Environment Compatibility Notes

**Original Platform:** macOS  
**Current Platform:** Linux (Ubuntu 22.04, x86_64)

### Changes Made for Linux Compatibility

The original repository was designed for macOS and included macOS-specific compiler flags. The following modifications have been made to ensure compatibility with Linux/GCC:

#### Makefile Changes:
- **Removed:** `-arch i386` and `-arch $(ARCH)` flags from all Makefiles (177 files)
  - These flags are macOS-specific for building 32-bit binaries
  - Not supported by Linux g++/gcc
- **Removed:** Unused `ARCH = i386` variable definitions

#### Build Environment:
- **Compiler:** gcc 11.4.0 (GNU Compiler Collection)
- **Debugger:** gdb 12.1 (GNU Debugger)
- **Build System:** GNU Make 4.3

All programs should now compile successfully on Linux systems using standard `make` commands.