//
//  ThreaderO8.h
//
//  Created by Robert R on 11/5/14.
//  Copyright (c) 2020 Robert Russell Millward. All rights reserved.
//

#ifndef ThreaderO8_h
#define ThreaderO8_h

//#include <stdio.h>
#include "ThreaderO4.h"

#pragma mark - Threading public

typedef struct ThreaderO8HelperClassApiStruct
{
    ThreaderZ4HCDataPT  (*findAvailableThread)();
    void (*releaseThread)(ThreaderZ4HCDataPT tmdP);
    void (*findAndExecute)(
        int count,
        void (*appList[])(ThreaderZ4HCDataPT tmdP),
        ThreaderZ4HCDataPT tmdP);
    int  (*isAnyThreadActive)();
    void (*exitThread)(ThreaderZ4HCDataPT data);
    void (*exitThreader)();
}ThreaderO8HCapiT, *ThreaderO8HCapiPT;

extern ThreaderO8HCapiT ThreaderO8HCapi;

#endif /* defined(ThreaderO8_h) */
