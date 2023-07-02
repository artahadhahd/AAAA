/*
    Initial commit by Arta on 28/06/2023
    GitHub: artahadhahd
    Website: artahadhahd.github.io
    MIT License
*/

#pragma once

#ifdef _WIN32
#define PLATFORM_WINDOWS
#include <gl/GL.h>
#include "SDL2/SDL.h"
#else
#include <GL/gl.h>
#include <SDL2/SDL.h>
#endif

// #ifdef main
// #undef main // SDL2 changes main to WinMain on Windows which makes some stuff incompatible
// #endif