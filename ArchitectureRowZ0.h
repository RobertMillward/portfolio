//
//  ArchitectureRowZ0.h
//
//  Created by Robert R on 10/17/19.
//  Copyright (c) 2019 Robert Russell Millward.  All rights reserved.
//

#ifndef ArchitectureRowZ0_h
#define ArchitectureRowZ0_h
/**
 * Some test constants.
 */
#define WIKIDB_REAL_APP     "WIKIDBA"
#define WIKIDB_SHARED_APP   "WIKIDBG"
/*
 */

#define ITEM_NAME_ROW   'w' // (What)
#define ID_ROW          'x' // (indeX)
#define STATUS_ROW      'y' // (whY)
#define SOURCE_ROW      'z' // what app created this row (whoZ)

typedef char    whatT [20+1]; // TODO
typedef char*   whatPT;

typedef char    whoZT [16+1]; // TODO (person 6, pplgrp 6, app 1, role 1, feature 1, step 1)
typedef char*   whoZPT;

typedef char    indeXT [9+1]; // TIME_INFO_Z_TIME
typedef char*   indeXPT;

typedef char    whYT [1+1];
typedef char*   whYPT;
typedef char    whYeT; // enum type

typedef char*   abstractRowT;

#endif 
/**
 */
//END ArchitectureRowZ0.h
