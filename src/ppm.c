/*
    Initial commit by Arta on 28/06/2023
    GitHub: artahadhahd
    Website: artahadhahd.github.io
    MIT License
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "ppm.h"

static void _ppmP1(uint32_t width, uint32_t height, FILE *file, PPM_File *p)
{
    size_t resolution = width * height;
    uint8_t *content = NULL;
    content = (uint8_t *)malloc(sizeof(uint8_t) * resolution);
    if (content == NULL) {
        p->content = NULL;
        return;
    }

    size_t counter = 0;
    for (size_t i = 0; i < resolution; i++) {
        int c;
        if (fscanf(file, "%1d", &c) == 1)
            counter++;
        if (c != 0 && c != 1) {
            free(content);
            p->content = NULL;
            return;
        }
        content[i] = c;
    }

    if (resolution != counter) {
        fprintf(stderr, "PPM resolution invalid");
        free(content);
        p->content = NULL;
        return;
    }
    p->content = content;
}

int ParsePPM(char *filename, PPM_File *dest)
{
    FILE *file;
    file = fopen(filename, "rb");
    if (file == NULL) {
        fprintf(stderr, "Couldn't open file %s\n", filename);
        return PpmIoError;
    }
    
    char header[3];
    uint32_t width, height;
    if (fscanf(file, "%2s %d %d", header, &width, &height) != 3) {
        fprintf(stderr, "Bad PPM header for %s\n", filename);
        return PpmBadHeader;
    }

    if (!strcmp(header, "P1")) {
        dest->header = P1;
        _ppmP1(width, height, file, dest);
    }
    else if (!strcmp(header, "P3"))
        dest->header = P3;
    else if (!strcmp(header, "P6"))
        dest->header = P6;
    else
        return PpmUnrecognized;

    dest->width = width;
    dest->height = height;
    if (fclose(file))
        return PpmIoError;
    return 0;
}