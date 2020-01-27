//
//  HexasoftO3.h
//
//  Created by Robert R on 2/18/2019.
//  Copyright (c) 2019 Robert Russell Millward.
//  All rights reserved.
//
/**
 *
 */
#ifndef __HexasoftO3__
#define __HexasoftO3__
#include "InitDestroyHelperO0.h"
#include "CommaSepO3.h"

typedef struct HexasoftO3toInstanceDataStruct // to for data
{
    // Not used, no additional data required
}HexasoftO3toIT, *HexasoftO3toIPT;

typedef struct HexasoftO3goInstanceMethodsStruct // go for methods
{
    void (* open)(char* file, CommaSepO3toIPT data);
    void (* read)(char* here, CommaSepO3toIPT data);
    int (* isAtEof)(CommaSepO3toIPT data);
    void (* close)(CommaSepO3toIPT data);
    
}HexasoftO3goIT, *HexasoftO3goIPT;

extern HexasoftO3goIT HexasoftO3go;

typedef struct HexasoftO3InstanceStruct // Having neither to nor go for complete instance
{
    CommaSepO3toIT to;  // the data
    HexasoftO3goIT go; // the methods
}HexasoftO3IT, *HexasoftO3IPT;

#define HexasoftIT HexasoftO3IT
#define HexasoftIPT HexasoftO3IPT

#define newHexasoft newHexasoftO3
extern HexasoftIT newHexasoft(gpTxPplGrpBatchTwoWayO0PT approvedParmName);

/**
 * Class methods
 */

typedef struct HexasoftO3ClassO3Struct
{
    void (* noMethods)(void);
}HexasoftO3CT, *HexasoftO3CPT;

#define HexasoftCT HexasoftO3CT
#define HexasoftC HexasoftO3C
extern HexasoftCT HexasoftC;

#define initHexasofts initHexasoftsO3
extern initStatusT initHexasofts(PermissionO0toIPT permissionP);

/**
 * Some test constants.
 */
#define HEXASOFT_PPLG   "HEXASFT"




#endif /* defined(__HexasoftO3__) */
