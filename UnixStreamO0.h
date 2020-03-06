//
//  UnixStreamO0.h
//  2020Mar10Dev
//
//  Created by Robert R on 10/17/14.
//  Copyright (c) 2020 Robert Russell Millward.  All rights reserved.
//
#ifndef UnixStreamO0_h
#define UnixStreamO0_h
// os
#include <stdlib.h>
#include <stdio.h>
// data plans
#include "ArchitectureZ0Plan.h"




/*
 */
#pragma mark - New instance
/*
 */
//extern UnixStreamO0IT newUnixStreamO0(void);
/*
 */
#pragma mark - Class Methods
/*
 */
typedef struct UnixStreamO0ServiceClassApiStruct
{
    FILE* (*fopen)(char *fullPath, char* X_UXSTRM);
    Ulng (*fwrite)(char* data, size_t itemSize, size_t itemCount, FILE* stream);
    Sint (*fflush)(FILE* stream);
    Uchr (*getc)(FILE* stream);
    Sint (*ungetc)(Uchr gotc, FILE* stream);
    Sint (*isEOF)(FILE* stream);
    Slng (*ftell)(FILE* stream);
    Ulng (*fread)(char* data, size_t itemSize, size_t itemCount, FILE* stream);
    char* (*getLine)(char* data, int size, FILE* stream);
    Sint (*fclose)(FILE* stream);
    Slng (*isError)(FILE* stream);
    void (*clearError)(FILE* stream);
    //FILE* (*memopen)(char* buf, int size, char* mode);
}UnixStreamO0SCapiT, *UnixStreamO0SCapiPT;
/*
#define RO_MODE_UXSTRM "r"
#define APPEND_MODE_UXSTRM "a"
#define TRUNCATE_MODE_UXSTRM "w"
#define IO_MODE_UXSTRM "+"
#define BINARY_MEMORY_UXSTRM "b"  // for use with fmemopen()
#define EXCLUSIVE_MODE_UXSTRM "x"
*/
#define UnixStreamSCapiT UnixStreamO0SCapiT
#define UnixStreamSCapi UnixStreamO0SCapi
extern UnixStreamSCapiT UnixStreamSCapi;

#endif /* UnixStreamO0_h */
/**
 *
 */











