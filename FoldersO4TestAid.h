//
//  FoldersO4TestAid.h
//
//  Created by Robert Russell Millward on 2/7/20.
//  Copyright © 2020 Robert Russell Millward. All rights reserved.
//
#ifndef FoldersO4TestAid_h
#define FoldersO4TestAid_h
#include "ArchitectureZ0Plan.h"


typedef struct FoldersO4QualityClassApiStruct
{
    void (*setupSuite)(lineNbrT);
    bool (*isScheduled)(cfileNameT, lineNbrT);
    char* (*getAssertText)(cfuncNameT, lineNbrT);
    
    void (*setupExistsSet1)(lineNbrT);
    bool (*doExistsSet1)(lineNbrT);
    void (*teardownExistsSet1)(lineNbrT);
    
    
    void (*setupGetInfoSet2)(lineNbrT);
    bool (*doGetInfoSet2)(lineNbrT);
    void (*teardownGetInfoSet2)(lineNbrT);
    
    void (*setupChangeSet3)(lineNbrT);
    bool (*doChangeSet3)(lineNbrT);
    void (*teardownChangeSet3)(lineNbrT);
    
    void (*teardownSuite)(lineNbrT);
    
}FoldersO4QCapiT, *FoldersO4QCapiPT;

extern FoldersO4QCapiT FoldersO4QCapi;


#endif /* FoldersO4TestAid_h */
/**
 *
 */
