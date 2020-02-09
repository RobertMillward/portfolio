//
//  BufferShareZ0TestAid.h
//  Both20FebMid
//
//  Created by Robert Russell Millward on 2/8/20.
//  Copyright © 2020 Robert Russell Millward. All rights reserved.
//
#ifndef BufferShareZ0TestAid_h
#define BufferShareZ0TestAid_h
// os
// helper api's
#include "BufferShareO0.h"
// data plans
// other
#define BS0_BFSZ 2000

typedef struct BufferShareO0QualityClassApiStruct
{
    void (*setupSuite0)(lineNbrT);
    bool (*isScheduled)(cfuncNameT, lineNbrT);
    char* (*getAssertText)(cfuncNameT, lineNbrT);
    
    void (*setupCreateDestroy)(lineNbrT);
    bool (*doCreateDestroy)(lineNbrT);
    void (*teardownCreateDestroy)(lineNbrT);
    
    void (*setupIsMoreDescriptionSizes)(lineNbrT);
    bool (*doIsMoreDescriptionSizes)(lineNbrT);
    void (*teardownIsMoreDescriptionSizes)(lineNbrT);
    
    void (*setupSet3)(lineNbrT);
    bool (*doSet3)(lineNbrT);
    void (*teardownSet3)(lineNbrT);
    
    void (*teardownSuite0)(lineNbrT);
    
}BufferShareO0QCapiT, *FoldersO4QCapiPT;

extern BufferShareO0QCapiT BufferShareO0QCapi;


//typedef struct BufferShareZ0QualiyInstanceThisStruct
//{
//    BufferShareZ0HIdataT data;
//    
//    // Instance functions:
//    BufferShareO0QIapiPT apiP;  // The externalized methods to keep the instance as small as possible.
//    
//} BufferShareO0QIthisT, *BufferShareO0QIthisPT;



/**
 * A newBufferShare reformats the input data (journal or commaSep)
 * so preserve the input row first as necessary.
 */
//extern BufferShareO0QIthisT newBufferShareZ0Test(char *jnlOrCsvLine, gpSllgChar64PT, lineNbrT);

#endif /* BufferShareZ0TestAid_h */
