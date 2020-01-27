//
//  HashBasicsZ0.h -  DELETE
//
//  Created by Robert R on 2/3/15.
//  Copyright (c) 2020 Robert Russell Millward.
//  All rights reserved.
//
#ifndef HashBasicsZ0_h
#define HashBasicsZ0_h
// os
// data plans
#include "ArchitectureZ0Plan.h"

#pragma mark - Class Methods
/*
 */
typedef struct HashBasicsZ0CtlS
{
    Uchr   doAtLeast;
    Uchr   maxShift;
    Uchr   condense;    // see HB_NO_CONDENSE
    Zchr   byCol;       // see HB_NO_COLUMNS
    Uint   hashMod;     // see HB_BIG_HASH_RSVD
    char *fs;
    char *rs;
    char *tokenNxtP;
    char *tokenBegP;
    char *tokenEndP;
}HashBasicsZ0CtlT, *HashBasicsZ0CtlPT;
#define HashBasicsCtlT HashBasicsZ0CtlT
#define HashBasicsCtlPT HashBasicsZ0CtlPT
/**
 * If reserved (preserved actually) then the
 * mod operator is not applied to the Ulng hash value
 * else the Ulng is % this value in the control structure.
 */
#define HB_BIG_HASH_RSVD 0
/**
 * Condensing can be used when hashing alpha-only.
 * The value of blank is subtracted before using
 * the character's value in the hash.
 */
#define HB_CONDENSE     1
#define HB_NO_CONDENSE  0
/**
 * Use if multiple column separators are as 1
 * else the zero based column number.
 */
#define HB_NO_COLUMNS   -1 // requires Pchr data type
#define HB_COL_NBR_BASE  0


typedef unsigned int    fourHashT;
typedef unsigned long   eightHashT;
/**
 * Tools to manage the 8100 (90*90) element array.
 * The array itself can be initialized with a negative value.
 * An element can hold an index into another array
 * or a count of items that hash to that cell.
 * Invoke with struct Hash8100S yourHashName[90*90]
 * and each element is yourHashName[yourIx].countOrIndex.
 * then initialize each element with a negative number.
 */
/**
 * For encoding 90x90 values which is 8100 which is just short of 8192 which is 2^13.
 * Add VISIBLE_ARC to get all printable characters.
 */
#define ENCODE_13b_ARC 90

struct Hash8100S
{
    long countOrIndex;
};
#define MAX_8100_HB 7688 // 31*31*8

typedef struct HashBasicsZ0ACapiS
{
    /**
     * Will not parse past '\0' or your row-separator(s).
     */
    eightHashT (*getBasicHash)(HashBasicsZ0CtlPT ctlP);
    
    /**
     * Mod the eightHashT by hashMod.
     */
    fourHashT (*getWordHash)(char *strP);
    
    /**
     * Create a hash which falls into the 90^2 (thus 8100) category
     * with an item name as input. It doesnt actually reach
     * 90^2 so the actual limit is noted by MAX_8100_HB.
     * The underscore character is ignored.
     */
    Ssht (*get8100HashForItemName)(char *strP);
    
    /**
     * Using get8100HashForItemName(), create a hash
     * which falls into the 90^2 category
     * with a name that might start with get, set, is, etc
     * then call get8100HashForItemName().
     */
    Ssht (*get8100HashForOtherName)(char *strP);
    /**
     * Convert the hash to 8100.
     */
    void (*get8100code)(char* the8100store, Ssht hash);
    
}HashBasicsO0HCapiT, *HashBasicsO0HCapiPT;

#define HashBasicsHCapiT HashBasicsO0HCapiT
#define HashBasicsHCapi HashBasicsO0HCapi
extern HashBasicsHCapiT HashBasicsHCapi;
/*
 */
#pragma mark - New instance
/*
 */
// none

#endif /* defined(HashBasicsZ0_h) */
