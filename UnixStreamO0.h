//
//  UnixStreamO0.h
//
//  Created by Robert R on 10/17/14.
//  Copyright (c) 2014 Robert Russell Millward.
//  All rights reserved.
//

#ifndef __UnixStreamO0__
#define __UnixStreamO0__
#import <stdlib.h>
#import "ArchitectureO0.h"
/*
 */
#pragma mark - init and destroy.
/*
 */

/*
 */
#pragma mark - The instance
/*
 */



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
typedef struct UnixStreamO0goClassMethodsStruct
{
    FILE* (*open)(char *fullPath, char* X_UXSTRM);
    Ulng (*write)(char* data, size_t itemSize, size_t itemCount, FILE* stream);
    Sint (*flush)(FILE* stream);
    Sint (*getc)(FILE* stream);
    Sint (*ungetc)(int gotc, FILE* stream);
    Sint (*isEOF)(FILE* stream);
    Slng (*tell)(FILE* stream);
    Ulng (*read)(char* data, size_t itemSize, size_t itemCount, FILE* stream);
    char* (*getLine)(char* data, int size, FILE* stream);
    Sint (*close)(FILE* stream);
    Slng (*isError)(FILE* stream);
    void (*clearError)(FILE* stream);
    FILE* (*memopen)(char* buf, int size, char* mode);
}UnixStreamO0goCT, *UnixStreamO0goCPT;

#define RO_MODE_UXSTRM "r"
#define APPEND_MODE_UXSTRM "a"
#define TRUNCATE_MODE_UXSTRM "w"
#define IO_MODE_UXSTRM "+"
#define BINARY_MEMORY_UXSTRM "b"  // for use with fmemopen()
#define EXCLUSIVE_MODE_UXSTRM "x"

#define UnixStreamCT UnixStreamO0goCT
#define UnixStreamC UnixStreamO0C
extern UnixStreamCT UnixStreamC;

#endif /* defined(__UnixStreamO0__) */











