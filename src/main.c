/*
Written by Arta on 28/06/2023
MIT
*/
#include <stdio.h>

#include "graphics.h"

#ifndef PPM_LIB
#include "ppm.h"
#endif

int main(void)
{
    PPM_File dest;
    int PPM = ParsePPM("test.ppm", &dest);
    if (PPM)
        puts("Bad PPM");
    printf("%d\n", dest.height);
    uint8_t *content = (uint8_t *)dest.content;
    printf("%d", content[0]);
    free(dest.content);
    return 0;
}