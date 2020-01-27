//
//  PeopleGroupO0.h
//
//  Created by Robert R on 11/3/14.
//  Copyright (c) 2014 Robert Russell Millward.
//  All rights reserved.
//
/**
* Special parameters notes for this package:
* - uses no memory so does not need group size and Id information
* - DOES transaction trace logging so does use the transaction Id (probably TRAN_IX) and isBatch information
* - may have versions using inheritance so has version and level information
*/
/**
 * For some low level routines.
 */

#ifndef __PeopleGroupO0__
#define __PeopleGroupO0__


//typedef char *   groupIdPT;
/**
 * Trace and space information about threading and customer size.
 */
typedef char    peopleGroupIdT [7+1];
typedef char*   peopleGroupIdPT;
typedef char    peopleGroupSigT [2+2];
typedef char*   peopleGroupSigPT;

#define TINY_PPLG         1
#define SMALL_PPLG        30
#define MEDIUM_PPLG       900
#define LARGE_PPLG        27000
#define VERY_LARGE_PPLG   810000
#define HUGE_PPLG         24300000



#endif /* defined(__PeopleGroupO0__) */
