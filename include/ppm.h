#pragma once

#ifndef PPM_LIB
#define PPM_LIB
#ifndef _GCC_WRAP_STDINT_H
#include <stdint.h>
#endif

enum PpmParseException {
    PpmUnrecognized = 2,
    PpmBadHeader = 3,
    PpmIoError = 3006, // same as EIO in errno.h
};

enum PPM_Header {
    P1,
    P3,
    P6,
};

typedef struct PPM_File {
    enum PPM_Header header;
    uint16_t width, height;
    uint8_t *content;
} PPM_File;

/// @param filename: the name of the file
/// @param dest: where you want to store the final result
/// @return 0 on success, error code on failure.
/// @author artahadhahd
int ParsePPM(char *filename, PPM_File *dest);
#endif /* End PPM_LIB */