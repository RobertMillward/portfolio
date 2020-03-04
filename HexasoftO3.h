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


typedef struct HexasoftO3ServiceInstanceApiStruct // go for methods
{
    void (* open)(char* file, CommaSepO3SIdataPT);
    void (* read)(char* here, CommaSepO3SIdataPT);
    int  (* isAtEof)(CommaSepO3SIdataPT);
    void (* close)(CommaSepO3SIdataPT);
    
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

typedef struct HexasoftO3ServiceClassApiStruct
{
    void (* noMethods)(void);
}HexasoftO3SCapiT, *HexasoftO3SCapiPT;

#define HexasoftSCapiT HexasoftO3SCapiT
#define HexasoftSCapi HexasoftO3SCapi
extern HexasoftSCapiT HexasoftSCapi;



#endif /* HexasoftO3_h */
/**
 *
 */
