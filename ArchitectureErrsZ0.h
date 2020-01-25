//
//  ArchitectureErrsZ0.h
//
//  Created by Robert R on 10/17/14.
//  Copyright (c) 2020 Robert Russell Millward.  All rights reserved.
//

#ifndef ArchitectureErrsZ0_h
#define ArchitectureErrsZ0_h

/**
 * Counting errors can be done independently of processing errors
 */
typedef struct ErrorWarningManagementStruct
{
    Uint classErrors;
    Uint classWarnings;
    Uint instanceErrors;     // aggregate
    Uint instanceWarnings;   // aggregate
}ErrorWarnCountT, *ErrorWarnCountPT;
extern ErrorWarnCountT aggregateZ0Counts;

/**
 * A few popular errors, can be returned in an initStatusT
 */
#define CEAOK   "0.AOK"
#define CEBUSY  "16.Busy"
#define CEINVAL "22.EINVAL"

#endif // ArchitectureErrsZ0.h
/**
 */
