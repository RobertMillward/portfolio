//
//  TimeSerNbrO0.h
//
//  Created by Robert Russell Millward on 12/24/18.
//  Copyright © 2018 Robert Russell Millward. All rights reserved.
//
#ifndef TimeSerNbrO0_h
#define TimeSerNbrO0_h
#include "TimeSerNbrZ0Plan.h"
/**
 *
 */
typedef const struct TimeSerNbrO0ApplicationClassStructure
{
    /**
     * Builds a structure of time information.
     * Is thread safe if a transaction id is not shared among threads.
     */
    void (*newTimeAndSerNbrNow)(theStampAIdataPT yourSpaceP);
    /**
     * Returns a string of the above time information.
     */
    Sint (*getStrOfTime)(gpSllgChar32PT yourSpaceP);
    /**
     *
     */
    Sint (*getRowOfSerNbr)(gpSllgChar32PT yourSpaceP);
    /**
     * Return a wwdW value where ww is weeks, d is days and W is W.
     * over 99 weeks and 6 days is 99+W.
     */
    void (*getAgeInWeeksAndDays)(gpSllgChar32PT yourSpaceP);
}TimeSerNbrO0ACapiT, *TimeSerNbrO0ACapiPT;

#define TimeSerNbrACapiT TimeSerNbrO0ACapiT
#define TimeSerNbrACapi TimeSerNbrO0ACapi
extern TimeSerNbrACapiT TimeSerNbrACapi;

#endif /* defined(TimeSerNbrO0_h) */
/**
 */
