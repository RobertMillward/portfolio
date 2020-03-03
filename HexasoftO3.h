//
//  HexasoftO3.h
//  2020Mar10Dev
//
//  Created by Robert R on 2/18/2019.
//  Copyright (c) 2019 Robert Russell Millward.  All rights reserved.
//
#ifndef HexasoftO3_h
#define HexasoftO3_h
//#include "InitDestroyHelperO0.h"
#include "CommaSepO3.h"

typedef struct HexasoftO3ServiceInstanceDataStruct // to for data
{
    // Not used, no additional data required
}HexasoftO3SIdataT, *HexasoftO3SIdataPT;

typedef struct HexasoftO3ServiceInstanceApiStruct // go for methods
{
    void (* open)(char* file, CommaSepO3SIdataPT data);
    void (* read)(char* here, CommaSepO3SIdataPT data);
    int  (* isAtEof)(CommaSepO3SIdataPT data);
    void (* close)(CommaSepO3SIdataPT data);
    
}HexasoftO3SIapiT, *HexasoftO3SIapiPT;

extern HexasoftO3SIapiT HexasoftO3SIapi;

typedef struct HexasoftO3ServiceInstanceStruct // Having neither to nor go for complete instance
{
    CommaSepO3SIdataT data;  // the data
    HexasoftO3SIapiT api; // the methods
}HexasoftO3SIthisT, *HexasoftO3SIthisPT;

#define HexasoftSIthisT HexasoftO3SIthisT
#define HexasoftSIthisPT HexasoftO3SIPthisT

#define newHexasoft newHexasoftO3
extern HexasoftSIthisT newHexasoft(gpSllgChar64PT);

/**
 * Class methods
 */

typedef struct HexasoftO3ClassO3Struct
{
    void (* noMethods)(void);
}HexasoftO3SCapiT, *HexasoftO3SCapiPT;

#define HexasoftSCapiT HexasoftO3SCapiT
#define HexasoftSCapi HexasoftO3SCapi
extern HexasoftSCapiT HexasoftSCapi;

//#define initHexasoft initHexasoftsO3
//extern initStatusT initHexasofts(PermissionO0toIPT permissionP);

/**
 * Some test constants.
 */
#define HEXASOFT_PPLG   "HEXASFT"




#endif /* HexasoftO3_h */
/**
 *
 */
