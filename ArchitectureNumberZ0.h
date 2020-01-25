//
//  ArchitectureNumberZ0.h
//
//  Created by Robert R on 10/17/19.
//  Copyright (c) 2014 Robert Russell Millward.
//  All rights reserved.
//

#ifndef ArchitectureNumberZ0_h
#define ArchitectureNumberZ0_h

// For strto*() and elsewhere
#define NO_ARG_PTR_ARC 0
#define RADIX_10_ARC 10

/**
 * Some types to make alignment of variable names easy.
 */
#define BITS_PER_BYTE_ARC 8
typedef unsigned char   U03b;       // 3 bits in 1 byte
typedef unsigned char   U06b;       // 6 bits in 1 byte
typedef          char   Schr;       // 1 byte
typedef unsigned char   Uchr;       // 1 byte
typedef unsigned char   Upct;       // 1 byte to 0.5%
typedef          short  Ssht;       // 2 bytes
typedef unsigned short  Usht;       // 2 bytes
typedef unsigned   int  Uint;       // x bytes
typedef            int  Sint;       // x bytes
typedef unsigned   int  U32b;       // x bytes
typedef          long   Slng;       // 4 bytes
typedef unsigned long   Ulng;       // 4 bytes
typedef      long long  Sllg;       // 8 bytes
typedef unsigned long long  Ullg;   // 8 bytes
typedef unsigned long long  U64b;   // 8 bytes
typedef          float  F1pr;
typedef         double  F2pr;


// Positive and zero values count;
// Negative is null value
typedef char        Zchr;
typedef short       Zsht;
typedef int         Zint;
typedef long        Zlng;
typedef long long   Zllg;

#pragma mark - Data types

typedef int lineNbrT;
typedef Ulng itemCountT;
typedef Ulng itemSizeT;

/**
 * Used to clarify that the sizeof the array in bytes
 * is being passed in as an argument.
 */
typedef size_t massOfT;

/**
 * A somewhat intelligent index
 */
typedef Ulng smartLngT;
#define SMARTIX_BAD -1

#endif // ArchitectureNumberZ0.h
