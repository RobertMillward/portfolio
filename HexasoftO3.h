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
    /**
     * Initialize the thesarus.
     */
    void (* hdrs)(CommaSepO3SIdataPT, gpSllgChar64PT);
    /**
     * Open the Hexasoft csv file.
     */
    void (* open)(peopleGroupIdT, devOrProdT, fileNmPT, CommaSepO3SIdataPT, gpSllgChar64PT);
    /**
     * Check for EOF
     */
    int  (* isAtEof)(CommaSepO3SIdataPT, gpSllgChar64PT);
    /**
     * Read one row.
     */
    void (* read)(char* here, massOfT, CommaSepO3SIdataPT, gpSllgChar64PT);
    /**
     * Load the data into the thesarus.
     * After or instead of this step, take and store the csv row data.
     */
    void (* csv)(char* here, CommaSepO3SIdataPT, gpSllgChar64PT);
    /**
     * Close the file and deque the thesarus.
     */
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
