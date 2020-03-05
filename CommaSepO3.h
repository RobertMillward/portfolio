//
//  CommaSepO3.h
//  2020Mar10Dev
//
//  Created by Robert Russell Millward  on 9/26/13.
//  Copyright (c) 2013 Robert Russell Millward.  All rights reserved.
//
#ifndef CommaSepO3_h
#define CommaSepO3_h
// os
#include <stdio.h>
// helper and service api's
// data plans
#include "ArchitectureZ0Plan.h"
#include "CommaSepZ3Plan.h"

//#define COMMASEP_PATH "Downloads/Sources/Databases"

/**
 * Instance methods.
 * Other methods may refer to these through the extern immediately below.
 */
typedef struct CommaSepO3ServiceInstanceApiStruct
{
    /**
     *
     */
    int (* close)(CommaSepO3SIdataPT, gpSllgChar64PT);
    /**
     * Prepare for this call by:
     * TwoWayZ0SCapi.setMustWork(&gp64P->twoWayP->twoWayStatusP);
     * TwoWayZ0SCapi.setMustFail(&gp64P->twoWayP->twoWayStatusP);
     */
    void (* openRead)(peopleGroupIdT, devOrProdT, fileNmPT, CommaSepO3SIdataPT, gpSllgChar64PT);
    /**
     *
     */
    void (* read)(int length, char *buffer, CommaSepO3SIdataPT, gpSllgChar64PT);
    /**
     *
     */
    bool (* isAtEof)(CommaSepO3SIdataPT, gpSllgChar64PT);
    
}CommaSepO3SIapiT, *CommaSepO3SIapiPT;

extern CommaSepO3SIapiT CommaSepO3SIapi;



typedef struct CommaSepO3ServiceInstanceThisStruct
{
    CommaSepO3SIapiPT apiP;
    CommaSepO3SIdataT data;
    
} CommaSepO3SIthisT, *CommaSepO3SIthisPT;
#define CommaSepSIthisT  CommaSepO3SIthisT
#define CommaSepSIthisPT CommaSepO3SIthisPT




#pragma mark - New CommaSep instance.

typedef struct CommaSepO3ServiceClassApiStruct
{
    /**
     * Copy the base path into the commaSep system.
     * If path is null or ""
     * then "." is used for the path;
     * The path is not checked for existing because
     * existing now does not guarantee existing later.\
     * Runs successfully only before calling init().
     */
    initStatusT     (*init)(pathPT, gpSllgChar64PT);
    /**
     *
     */
    CommaSepSIthisT (*newThis)(gpSllgChar64PT);
}CommaSepO3SCapiT, *CommaSepO3SCapiPT;

#define CommaSepSCapiT CommaSepO3SCapiT
#define CommaSepSCapi CommaSepO3SCapi
extern CommaSepSCapiT CommaSepSCapi;

#endif  // CommaSepO3_h
/**
 *
 */
