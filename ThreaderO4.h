//
//  ThreaderO4.h
//
//  Created by Robert R on 11/1/14.
//  Copyright (c) 2020 Robert Russell Millward. All rights reserved.
//
#ifndef ThreaderO4_h
#define ThreaderO4_h
// os
#import <pthread.h>
// data plan
#import "ArchitectureZ0Plan.h"
// api


typedef struct tZ8onlyS
{
    int groupSize;
}tZ8only;


typedef struct ThreadMgrDataS
{
    int threadIX;
    tranIxT bizTranIX;
    Ullg startTime;
    int requestID;
    Ulng memSize;
    Ulng usecEstimate;
    int percentRemaining;
#define TM_MIN_PCT 2
    int isBeingScheduled;
    char *msgStr;
    char* msgRow;//RowP msgRow;
    void (*app)(struct ThreadMgrDataS *my);
    // Below here is for ThreaderO8
    // (pure C can't extend)
    tZ8only t8;
    
}ThreaderZ4HCDataT, *ThreaderZ4HCDataPT;

#pragma mark - Threading public

typedef char* initStatusT; // TODO

typedef struct ThreaderO4HelperClassApiStruct
{
    initStatusT (*init)();
    ThreaderZ4HCDataPT  (*findAvailableThread)();
    void (*releaseThread)(ThreaderZ4HCDataPT tmdP);
    void (*execute)(ThreaderZ4HCDataPT tmdP);
    int  (*isAnyThreadActive)();
    void (*exitThread)(ThreaderZ4HCDataPT data);
    void (*exitThreader)();
}ThreaderO4HCapiT, *ThreaderO4HCapiPT;

extern ThreaderO4HCapiT ThreaderO4HCapi;


#endif /* defined(ThreaderO4_h) */
