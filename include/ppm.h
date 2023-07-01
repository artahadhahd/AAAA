#pragma once

#ifndef _GCC_WRAP_STDINT_H
#include <stdint.h>
#endif

#ifndef PPM_LIB
#define PPM_LIB
#define PPM_UNRECOGNIZED    2
#define PPM_BAD_HEADER      3
#define PPM_IO_ERROR        3006 // same as EIO
#endif

enum PPM_Header {
    P1,
    P3,
    P6,
};

typedef struct PPM_File {
    enum PPM_Header header;
    uint16_t width, height;
    void *content;
} PPM_File;

/// @param filename: the name of the file
/// @param dest: where you want to store the final result
/// @return 0 on success, error code on failure.
/// @author artahadhahd
int ParsePPM(char *filename, PPM_File *dest);
