//
//  SortMergeZ0TestAid.h - interface file for all level 0 quality assurance code silo parts common to all versions
//
//  Created by Robert R on 11/2/19.
//  Copyright © 2020 Robert Russell Millward. All rights reserved.
//

#ifndef SortMergeZ0TestAid_h
#define SortMergeZ0TestAid_h

#include <stdio.h>
#include "SortMergeZ0.h" // Need the api and the plan

typedef enum SortMergeFillOrderQ0enum
{
    FILL_RANDOM,
    FILL_ASCENDING,
    FILL_DESCENDING
}sortMergeFillOrderQ0T;

/**
 * The SortMerge applcation silo quality assurance class api
 */
typedef struct SortMergeZ0QCLineApiStruct
{
    long (*sort)(uhxPassPT, int lineNbr);
    int  (*clang)(uhxPassPT, int lineNbr);
    void (*brute)(uhxPassPT, int lineNbr);
    /**
     * New
     */
    uhxPassT (*newInfo)(uhxElPT, size_t massOf, uhxSubTypeT, sortMergeFillOrderQ0T, int lineNbr);
    /**
     * Tools
     */
    void (*fillRandom)(uhxElPT, size_t, uhxSubTypeT, int lineNbr);
    void (*fillAscending)(uhxElPT, size_t, uhxSubTypeT, int lineNbr);
    void (*fillDescending)(uhxElPT, size_t, uhxSubTypeT, int lineNbr);
    
    uhxIxNoMoreT (*sortCouplets)(uhxPassPT, int lineNbr);
    uhxIxNoMoreT (*seqChk)(uhxPassPT, int lineNbr);
    
    void (*slosh)(uhxPassPT, int lineNbr);
    void (*btree)(uhxPassPT, int lineNbr);
    
}SortMergeZ0QClineApiT, * SortMergeZ0QClineApiPT;

extern SortMergeZ0QClineApiT SortMergeZ0QClineApi;

#endif /* SortMergeZ0QTestAid_h */
/**
 */
