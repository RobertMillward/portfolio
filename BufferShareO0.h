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
#include "BufferShareZ0Plan.h"    // must be here to define api argument
//#include "ArchitectureZ0Plan.h" // BufferShareZ0Plan.h provides

typedef struct BufferShareO0HelperInstanceApiStruct
{
    /**
     * get the number of bytes from loadHere
     * to bufEnd as, for example, how long
     * of a file can be read.
     */
    Ulng (*getSizeForLoad)(BufferShareZ0HIdataPT, gpSllgChar64PT);
    
    /**
     * Setup for readCurrent().
     */
    bool (*isMore)      (BufferShareZ0HIdataPT, gpSllgChar64PT);
    
    /**
     * This reads phase 1 or phase 2 data.
     * If the next read will not overlap the  current write
     * then set currentRead to nextRead.
     * Note that now the output can be safely broken into fields.
     */
    void (*readCurrent)(BufferShareZ0HIdataPT, gpSllgChar64PT);
    
    /**
     * This allows the caller to write phase 1 data into the phase 2 storage.
     * If room between currentWrite and bufEnd then TODO
     * store incoming string at currentWrite then
     * increment currentWrite by that length plus one.
     */
    void (*writeCurrent)(BufferShareZ0HIdataPT, char *data, gpSllgChar64PT);
    
    /**
     * The caller is quitting the current phase so move to the next phase.
     * The phases are :
     * 1) load and process \n or \036 terminated rows
     *    from a null terminated buffer
     * 2) process the resulting null terminated rows
     * 3) all done
     */
    void (*nextPhase)   (BufferShareZ0HIdataPT, gpSllgChar64PT);
    
    /**
     * Into caller's buffer of  at least BS0_DESC_SZ
     * put a description of the current state of this instance.
     * Note: read and write counts may be -1 upon encountering undefined errors.
     */
    void (*description)(BufferShareZ0HIdataPT, char *here, gpSllgChar64PT);
    
    /**
     * Into the transaction log put current statics
     * then clean up.
     */
    void (*destroy)     (BufferShareZ0HIdataPT, gpSllgChar64PT);
    
}BufferShareO0HIapiT, *BufferShareO0HIapiPT;

extern BufferShareO0HIapiT BufferShareO0HIapi;

/**
 *
 */
typedef struct BufferShareO0HelperInstanceThisStruct
{
    BufferShareO0HIapiPT apiP;
    BufferShareZ0HIdataT data;
    
}BufferShareO0HIthisT, *BufferShareO0HIthisPT;


typedef struct BufferShareO0HelperClassApiStruct
{
    BufferShareO0HIthisT (*newThis)(char* bufFirstByte, char* bufLastByte, gpSllgChar64PT);
    
    BufferShareZ0HIdataT (*newData)(char* bufFirstByte, char* bufLastByte, gpSllgChar64PT);
    
}BufferShareO0HCapiT, *BufferShareO0HCapiPT;

extern BufferShareO0HCapiT BufferShareO0HCapi;

#endif /* BufferShareO0_h */
/**
 *
 */
