//
//  HashBasicsZ0TestAid.h
//
//  Created by Robert Russell Millward on 2/14/20.
//  Copyright © 2020 Robert Russell Millward. All rights reserved.
//
#ifndef HashBasicsZ0TestAid_h
#define HashBasicsZ0TestAid_h
#include "ArchitectureZ0Plan.h"
/**
 * The definition of the Quality Class interface for HashBasics.
 * It currently does not use the standard testing structure.
 */
typedef struct HashBasicsZ0QualityClassApiStruct
{
    void (*setupSuite)(lineNbrT);
    bool (*isScheduled)(cfileNameT, lineNbrT);
    char* (*getAssertText)(cfuncNameT, lineNbrT);
    
    void (*setupParseSet1)(lineNbrT);
    bool (*doParseSet1)(lineNbrT);
    void (*teardownParseSet1)(lineNbrT);
    
    
    void (*setup8100Set2)(lineNbrT);
    bool (*do8100Set2)(lineNbrT);
    void (*teardown8100Set2)(lineNbrT);
    
    void (*setupParseTestAidSet3)(lineNbrT);
    bool (*doParseTestAidSet3)(lineNbrT);
    void (*teardownParseTestAidSet3)(lineNbrT);
    
    void (*setupSet4)(lineNbrT);
    bool (*doSet4)(lineNbrT);
    void (*teardownSet4)(lineNbrT);
    
    void (*teardownSuite)(lineNbrT);
    
}HashBasicsZ0QCapiT, *HashBasicsZ0QCapiPT;

extern HashBasicsZ0QCapiT HashBasicsZ0QCapi;

#endif /* HashBasicsZ0TestAid_h */
