//
//  ErrorHelperO0.h
//
//  Created by Robert R on 10/17/14.
//  Copyright (c) 2020 Robert Russell Millward.  All rights reserved.
//
#ifndef ErrorHelperO0_h
#define ErrorHelperO0_h
// os
#include <errno.h>
// data
// api


typedef struct ErrorHelperO0HelpClassStruct
{
    char *(*set)(char *msgStr, int base); // Do first, never thread safe
    char *(*get)(int msgIx);    // error code, x.missing, not init, invalid
    
}ErrorHelperO0SCapiT, *ErrorHelperO0SCapiPT;

#define ErrorHelperSCapiT ErrorHelperO0SCapiT
#define ErrorHelperSCapi ErrorHelperO0SCapi
extern ErrorHelperSCapiT ErrorHelperSCapi;

//#define ErrorHelperACapi ErrorHelperO0HCapi // until they are all fixed

#endif /* defined(ErrorHelperO0_h) */
/**
 */











