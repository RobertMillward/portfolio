//
//  FoldersO4TestAid.h
//
//  Created by Robert Russell Millward on 2/7/20.
//  Copyright © 2020 Robert Russell Millward. All rights reserved.
//
#ifndef FoldersO4TestAid_h
#define FoldersO4TestAid_h
#include "ArchitectureZ0Plan.h"
//#include "ErrorHelperZ0Plan.h"

typedef struct FoldersO4QualityClassApiStruct
{
    void (*setupSuite0)(lineNbrT);
    bool (*isScheduled)(cfileNameT);
    char* (*getAssertText)(cfuncNameT);
    
    void (*setupSet1)(lineNbrT);
    bool (*doSet1)(lineNbrT);
    void (*teardownSet1)(lineNbrT);
    
    
    void (*setupSet2)(lineNbrT);
    bool (*doSet2)(lineNbrT);
    void (*teardownSet2)(lineNbrT);
    
    void (*setupSet3)(lineNbrT);
    bool (*doSet3)(lineNbrT);
    void (*teardownSet3)(lineNbrT);
    
    void (*teardownSuite0)(lineNbrT);
    
}FoldersO4QCapiT, *FoldersO4QCapiPT;

extern FoldersO4QCapiT FoldersO4QCapi;


#endif /* FoldersO4TestAid_h */
/**
 *
 */
