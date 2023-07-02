#!/usr/bin/env python3

"""
    Initial commit by Arta, 28/06/2023
    A script to assist with compiling and debugging.
    GitHub: artahadhahd
    Website: artahadhahd.github.io/
    MIT License
"""

from pathlib import Path
import os
import sys

WARNINGS = "-Werror -Wall -Wextra -Wno-unused-variable -Wno-unused-parameter"
INCLUDE = "-Iinclude -Ilib/win32"
DLLS = "-lopengl32 -lgdi32 -lSDL2"

def get_help():
    print("Available commands:")
    print("install.py             => Compile for your platform")
    print("install.py -g [ 0..3 ] => Compile for debugging (meant for developers)")
    print("install.py -h          => Show this help message")

def compile(*, debug_flags: str):
    if os.name == 'nt':
        if os.system("gcc --version >nul 2>&1"):
            print("Make sure you have gcc installed. Install it with mingw32. For more information see https://winlibs.com/")
            sys.exit(1)
        if not Path('bin').exists():
            os.mkdir('bin')
        a = f'gcc {debug_flags} src/*.c -o bin/PPM.exe {INCLUDE} -Llib/win32/SDL2/{[64, 32][Path("C:/Program Files (x86)").exists()]} {DLLS} {WARNINGS}'
        print(a)
        output = os.system(a)
        if output:
            print("\n---------\nCompilation failed. See above for more details. Report bugs to https://github.com/artahadhahd/AAAA")
            sys.exit(1)
    print("Compiled successfully. Executable in bin/PPM.exe")

if len(option := sys.argv) != 1:
    first_arg = option[1].lower()
    if first_arg == '-g':
        print("Compiling for debug mode")
        if len(option) == 3:
            if int(option[2]) < 0 or int(option[2]) > 3:
                raise RuntimeError("Invalid amount of debug level")
            compile(debug_flags=f"-g{int(option[2])}")
        else:
            compile(debug_flags='-g')
        if (start := input("Start debugging with gdb? [Y/n] ").lower()) == '' or start == 'y' or start == 'yes':
            os.system('gdb bin/PPM.exe')
        else:
            sys.exit(0)
    if first_arg == '-h':
        get_help()
        sys.exit(0)
    else:
        print("Invalid option")
compile(debug_flags='')