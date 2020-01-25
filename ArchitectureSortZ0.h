//
//  ArchitectureSortZ0.h
//
//  Created by Robert R on 10/17/19.
//  Copyright (c) 2020 Robert Russell Millward.  All rights reserved.
//

#ifndef ArchitectureSortZ0_h
#define ArchitectureSortZ0_h

#define NULLS_HI_ARC 'H'
#define NULLS_LO_ARC 'L'

typedef char sortNullsArcT;

// These are guaranteed to be comparable.
#define UNDEFINED_ARC "999.Sort undefined"
#define NULL_HI_ARC   "998.A null hi"
#define IS_HIGH_ARC   "997.A after B"
#define IS_EQL_ARC    "996.A equals B"
#define IS_LOW_ARC    "995.A before B"
#define NULL_LO_ARC   "994.A null low"
#define NOT_LIKE_ARC  "993.A not like B"
#define IS_LIKE_ARC   "992.A is like B"

typedef char* compareResultArcT;

#endif // ArchitectureSortZ0_h
/**
 */
