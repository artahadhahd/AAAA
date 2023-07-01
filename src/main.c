/*
Written by Arta on 28/06/2023
MIT
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// #include "graphics.h"

#ifndef PPM_LIB
#include "ppm.h"
#endif

int main(void)
{
    PPM_File dest;
    int PPM = ParsePPM("a.ppm", &dest);
    if (PPM) {
        puts("Bad PPM");
        return -1;
    }
    printf("%d\n", dest.height);
    if (dest.content != NULL) {
        for (int i = 0; i < dest.height * dest.width; i++)
            printf("%d\n", dest.content[i]);
    }
    free(dest.content);
}