//
//  BufferShareO0.h
//
//  Created by Robert Russell Millward on 2/6/20.
//  Copyright © 2020 Robert Russell Millward. All rights reserved.
//
#ifndef BufferShareO0_h
#define BufferShareO0_h
// os
// helper api's
// data plans
#include "ArchitectureZ0Plan.h"
#include "BufferShareZ0Plan.h"

typedef struct BufferShareO0HelperClassApiStruct
{
    BufferShareZ0dataT (*newData)(char* bufFirstByte, char* bufLastByte, gpSllgChar64PT);
    /**
     * get the number of bytes from loadHere
     * to bufEnd as, for example, how long
     * of a file can be read.
     */
    Ulng (*getSizeForLoad)(BufferShareZ0dataPT);
    
    /**
     * Setup for readCurrent().
     */
    bool (*isMore)      (BufferShareZ0dataPT);
    
    /**
     * If the next read will not overlap the
     * current write
     * then set currentRead to nextRead.
     * Note that the string can safely be
     * broken into fields.
     */
    void (*readCurrent)(BufferShareZ0dataPT);
    
    /**
     * If room between currentWrite and bufEnd then
     * store incoming string at currentWrite then
     * increment currentWrite by that length plus
     * one.
     */
    void (*writeCurrent)(BufferShareZ0dataPT, char *data);
    
    /**
     * If the caller is quitting the current
     * phase then move to the next phase. The
     * phases are :
     * 1) load and process \n terminated rows
     *    in a null terminated buffer
     * 2) process null terminated rows
     * 3) all done
     */
    void (*nextPhase)   (BufferShareZ0dataPT);
    
    /**
     * Into caller's buffer of BS0_DESC_SZ
     * put a description of the current state
     * of this instance.
     */
    void (*description)(BufferShareZ0dataPT, char *here);
    
    /**
     * Into the transaction log put current statics
     * then clean up.
     */
    void (*destroy)     (BufferShareZ0dataPT);
    
}BufferShareO0HCapiT, *BufferShareO0HCapiPT;

extern BufferShareO0HCapiT BufferShareO0HCapi;

#endif /* BufferShareO0_h */
/**
 *
 */
