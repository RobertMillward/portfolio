//
//  BufferShareO0.h
//
//  Created by Robert Russell Millward on 2/6/20.
//  Copyright © 2020 Robert Russell Millward. All rights reserved.
//
#ifndef BufferShareO0_h
#define BufferShareO0_h

typedef struct BufferShareO0HelperClassApiStruct
{
    BufferShareT newBufferShare(char* bufFirstByte, char* bufLastByte, gpTxPplGrpBatchTwoWayO0PT gpTxEtAl);
    /**
     * get the number of bytes from loadHere
     * to bufEnd as, for example, how long
     * of a file can be read.
     */
    Ulng (*getSizeForLoad)(struct BufferShareO0S *this);
    
    /**
     * Setup for readCurrent().
     */
    bool (*isMore)(struct BufferShareO0S *this);
    
    /**
     * If the next read will not overlap the
     * current write
     * then set currentRead to nextRead.
     * Note that the string can safely be
     * broken into fields.
     */
    void (*readCurrent)(struct BufferShareO0S *this);
    
    /**
     * If room between currentWrite and bufEnd then
     * store incoming string at currentWrite then
     * increment currentWrite by that length plus
     * one.
     */
    void (*writeCurrent)(struct BufferShareO0S *this, char *data);
    
    /**
     * If the caller is quitting the current
     * phase then move to the next phase. The
     * phases are :
     * 1) load and process \n terminated rows
     *    in a null terminated buffer
     * 2) process null terminated rows
     * 3) all done
     */
    void (*nextPhase)(struct BufferShareO0S *this);
    
    /**
     * Into caller's buffer of BS0_DESC_SZ
     * put a description of the current state
     * of this instance.
     */
#define BS0_DESC_SZ 50
    void (*description)(struct BufferShareO0S *this, char *here);
    
    /**
     * Into the transaction log put current statics
     * then clean up.
     */
    void (*destroy)(struct BufferShareO0S *this);
    
}BufferShareO0HCapiT, *BufferShareO0HCapiPT;

#endif /* BufferShareO0_h */
/**
 *
 */
