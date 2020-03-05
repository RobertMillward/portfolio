//
//  HexasoftZ3TestAid.h
//  2020Mar10Dev
//
//  Created by Robert Russell Millward on 3/3/20.
//  Copyright © 2020 Robert Russell Millward. All rights reserved.
//
#ifndef HexasoftZ3TestAid_h
#define HexasoftZ3TestAid_h
// os
// helper and service api's
// data plans
#include "ArchitectureZ0Plan.h"
// quality

typedef struct HexasoftZ3QualityClassApiStructure
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
}HexasoftZ3QCapiT, *HexasoftZ3QCapiPT;

extern HexasoftZ3QCapiT HexasoftZ3QCapi;

#endif /* HexasoftZ3TestAid_h */
/**
 *
 */
