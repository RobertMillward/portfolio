//
//  ArchitecturePplGrpZ0.h
//
//  Created by Robert R on 10/17/19.
//  Copyright (c) 2014 Robert Russell Millward.
//  All rights reserved.
//
/**
 * The essence of PeopleGroup which can indicate memory requirements
 */
#ifndef ArchitecturePplGrpZ0_h
#define ArchitecturePplGrpZ0_h

typedef int     pplGrpSizeT;
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

#endif // ArchitecturePplGrpZ0.h
