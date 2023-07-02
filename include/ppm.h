/*
    Initial commit by Arta on 28/06/2023
    GitHub: artahadhahd
    Website: artahadhahd.github.io
    MIT License
*/

#pragma once

#ifndef PPM_LIB
#define PPM_LIB
#ifndef _GCC_WRAP_STDINT_H
#include <stdint.h>
#endif

enum PpmParseException {
    PpmUnrecognized = 2,
    PpmBadHeader = 3,
    PpmIoError = 5, // same as EIO in errno.h on linux. IBM specifies 3006
};

enum PPM_Header {
    P1,
    P3,
    P6,
};

typedef struct PPM_File {
    enum PPM_Header header; // P1, P3, P6 at the moment
    uint32_t width, height;
    uint8_t *content;       // a malloc'd array of size self.width * self.height, make SURE to free...
} PPM_File;

/// @param filename the path to the desired file
/// @param dest where you want to store the final result
/// @return 0 on success, error code on failure. See "enum PPM_Header" in ppm.h
/// @author artahadhahd
int ParsePPM(char *filename, PPM_File *dest);
#endif /* End PPM_LIB */