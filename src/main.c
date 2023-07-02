/*
    Initial commit by Arta on 28/06/2023
    GitHub: artahadhahd
    Website: artahadhahd.github.io
    MIT License
*/
#include <stdio.h>

#include <stdlib.h>
#include <stdint.h>

#include "graphics.h"

#ifndef PPM_LIB
#include "ppm.h"
#endif

#ifdef PLATFORM_WINDOWS
int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
#else
int main(void)
#endif
{
    PPM_File dest;
    int PPM = ParsePPM("a.ppm", &dest);
    if (PPM) {
        puts("Bad PPM");
        return -1;
    }
    printf("%d\n", dest.height);
    if (dest.content != NULL) {
        for (uint32_t i = 0; i < dest.height * dest.width; i++)
            printf("%d\n", dest.content[i]);
    }
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        free(dest.content);
        printf("%s\n", SDL_GetError());
        return 1;
    }
        SDL_Window *window = NULL;
    window = SDL_CreateWindow("AAAAA", 20, 20, 120, 500, SDL_WINDOW_FULLSCREEN|SDL_WINDOW_RESIZABLE);

    if (window == NULL) {
        puts("Fucking window won't start");
        return -1;
    }

    SDL_Event e;
    while (1) {
        while (SDL_PollEvent(&e)) {
            switch (e.type) {
                case SDL_QUIT:
                    goto EXITS;
            }
        }
    }
EXITS:
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}