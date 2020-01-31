//
//  DataAidY0Plan.h
//
//  Created by Robert R on 01/08/20.
//  Copyright (c) 2020 Robert Russell Millward.  All rights reserved.
//
#ifndef DataAidY0Plan_h
#define DataAidY0Plan_h
// os
// data plan
#include "ArchitectureZ0Plan.h"



/**
 * Up to 32 people per logical lot * floors available if apartment
 * A typical city lot is 2 apartment floors by 4 apartment floors.
 */

typedef struct BitsOfXStruct
{
    Ulng stateX:3;
    Ulng cityX: 3;
    Ulng lotX:  9;
#define SOUTH_DIRECTION 1
#define EAST_DIRECTION 0
    Ulng direction:1;
    Ulng moreToDo:1;      // 1 = yes
    Ulng firstTimeIn:1;   // 1 = yes
    Ulng filler:9;
    Ulng familySize:3;  // number of people in families in this column
}BitsOfXForY0T;

typedef struct BitsOfYStruct
{
    Ulng stateY: 2;
    Ulng cityY:  3;
    Ulng lotY:  10;
    Ulng filler:17;
}BitsOfYForY0T;

typedef struct DataAidLocY0HelperClassLocStruct
{
    BitsOfXForY0T x; // lot location east to west
    BitsOfYForY0T y; // lot location north to south
    Ulng seedAfterCity;
    Ulng seedAfterStreet;
    Ulng seedAfterLot;
    Uchr floor; // floor at this address, count down
    Uchr personNumber; // 0x02 says 0x01 counts as travel direction
}DataAidLocY0HClocT, *DataAidLocY0HClocPT;


#endif /* defined(DataAidY0Plan_h) */
/**
 
 */
