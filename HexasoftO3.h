//
//  HexasoftO3.h
//  2020Mar10Dev
//
//  Created by Robert R on 2/18/2019.
//  Copyright (c) 2020 Robert Russell Millward.  All rights reserved.
//
#ifndef HexasoftO3_h
#define HexasoftO3_h
#include "CommaSepO3.h"


typedef struct HexasoftO3ServiceInstanceApiStruct
{
    void (* open)(peopleGroupIdT, devOrProdT, fileNmPT, CommaSepO3SIdataPT, gpSllgChar64PT);
    void (* read)(char* here, massOfT, CommaSepO3SIdataPT, gpSllgChar64PT);
    int  (* isAtEof)(CommaSepO3SIdataPT, gpSllgChar64PT);
    void (* close)(CommaSepO3SIdataPT, gpSllgChar64PT);
    
}HexasoftO3SIapiT, *HexasoftO3SIapiPT;

extern HexasoftO3SIapiT HexasoftO3SIapi;

typedef struct HexasoftO3ServiceInstanceStruct // Having neither to nor go for complete instance
{
    CommaSepO3SIdataT   data;
    HexasoftO3SIapiT    api;
}HexasoftO3SIthisT, *HexasoftO3SIthisPT;

#define HexasoftSIthisT HexasoftO3SIthisT
#define HexasoftSIthisPT HexasoftO3SIPthisT


/**
 * Class methods
 */
typedef struct HexasoftO3ServiceClassApiStruct
{
    initStatusT     (* init)    (pathPT, gpSllgChar64PT);
    HexasoftSIthisT (*newThis)  (gpSllgChar64PT);
}HexasoftO3SCapiT, *HexasoftO3SCapiPT;

#define HexasoftSCapiT HexasoftO3SCapiT
#define HexasoftSCapi HexasoftO3SCapi
extern HexasoftSCapiT HexasoftSCapi;



#endif /* HexasoftO3_h */
/**
 *
 */
