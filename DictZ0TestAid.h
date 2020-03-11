//
//  DictZ0TestAid.h
//  2020Apr02Dev
//
//  Created by Robert Russell Millward on 12/4/19.
//  Copyright (c) 2020 Robert Russell Millward. All rights reserved.
//
#ifndef DictZ0TestAid_h
#define DictZ0TestAid_h
// os
// helper api's
#include "DictO0.h"
// data plans
// app api's
// quality

/**
 * A thread safe library to support the stages of Dict creation.
 */

typedef struct DictO0QualityClassApiStructure
{
    void (*setupSuite)(lineNbrT);
    bool (*isScheduled)(cfileNameT, lineNbrT);
    char* (*getAssertText)(cfuncNameT, lineNbrT);
    
    void (*setupSet1)(lineNbrT);
    bool (*doSet1SizeSafe)(lineNbrT);
    void (*teardownSet1)(lineNbrT);
    
    
    void (*setupSet2)(lineNbrT);
    bool (*doSet2Basics)(lineNbrT);
    void (*teardownSet2)(lineNbrT);
    
    void (*setupSet3)(lineNbrT);
    bool (*doSet3ExtraDemo)(lineNbrT);
    void (*teardownSet3)(lineNbrT);
    
    void (*setupSet4)(lineNbrT);
    bool (*doSet4Performance)(lineNbrT);
    void (*teardownSet4)(lineNbrT);
    
    void (*teardownSuite)(lineNbrT);
}DictO0QCapiT, *DictO0QCapiPT; // these will be O0 when conversion is complete.

extern DictO0QCapiT DictO0QCapi;

#endif /* DictZ0TestAid_h */
/**
 * The testing of the thesarus is done with Hexasoft, FamilyHistory, and similar processes.
 */
