//
//  MemoryEtcZ0Plan.h
//  2020Apr21Dev
//
//  Created by Robert Russell Millward on 4/20/20.
//  Copyright © 2020 Robert Russell Millward. All rights reserved.
//
#ifndef MemoryEtcZ0Plan_h
#define MemoryEtcZ0Plan_h
// os
// helper and service api's
// data plans
#include "ArchitectureZ0Plan.h"

typedef struct MemoryEtcZ0_MallocFreeStruct
{
    void* startHeapP;
    void* beyondHeapP;
}mallocFreeDataT, *mallocFreeDataPT;

typedef Slng lengthT;
typedef Slng countT;

typedef struct MemoryEtcZ0_ApiStruct
{
    /**
     * Get some heap memory.
     * If count is zero (0) then it is treated as one (1).
     */
    mallocFreeDataT (*mallocFav)(lengthT, countT);
    /**
     * Free the memory
     */
    void            (*freeFav)(mallocFreeDataPT);
    
}MemoryEtcZ0apiT, *MemoryEtcZ0apiPT;

extern MemoryEtcZ0apiT MemoryEtcZ0api;

#endif /* MemoryEtcZ0Plan_h */
/**
 *
 */
