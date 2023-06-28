#!/usr/bin/env python3

# Written by Arta, 28/06/2023
from pathlib import Path
import os
import sys

WARNINGS = "-Werror -Wall -Wextra -Wno-unused-parameter"
INCLUDE = "-Iinclude -Ilib/win32"

if os.name == 'nt':
    if os.system("gcc --version >nul 2>&1"):
        print("Make sure you have gcc installed. Install it with mingw32. For more information see https://winlibs.com/")
        sys.exit(1)
    if not Path('bin').exists():
        os.mkdir('bin')
    if Path('C:\Program Files (x86)').exists(): # if 32-bit
        output = os.system(f'gcc src/*.c -o bin/PPM.exe {INCLUDE} -Llib/win32/SDL2/32 -lSDL2 {WARNINGS}')
    else:
        output = os.system(f'gcc src/*.c -o bin/PPM.exe {INCLUDE} -Llib/win32/SDL2/64 -lSDL2 {WARNINGS}')
    if output:
        print("\nCompilation failed. See above for more details. Report bugs to https://github.com/artahadhahd/AAAA")
        sys.exit(1)
    sys.exit(0)