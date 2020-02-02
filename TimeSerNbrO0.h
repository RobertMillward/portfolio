//
//  TimeSerNbrO0.h
//
//  Created by Robert Russell Millward on 12/24/18.
//  Copyright © 2020 Robert Russell Millward. All rights reserved.
//
#ifndef TimeSerNbrO0_h
#define TimeSerNbrO0_h
#include "TimeSerNbrZ0Plan.h"
/**
 *
 */
typedef const struct TimeSerNbrO0HelperClassStructure
{
    /**
     * Builds a structure of time information.
     * Is thread safe if a transaction id is not shared among threads.
     * NodeId is a subset of the TimeSerNbrRow.
     */
    void (*newTimeAndSerNbrNow)(theStampAIdataPT);
    /**
     * Returns a string in Char32 of your Sllg seconds and micro seconds value.
     */
    Zint (*getStrOfTime)(gpSllgChar32PT);
    /**
     * Get a whole row or only the node.
     */
    Zint (*getRowOfSerNbr)(gpSllgChar32PT);
    Zint (*getNodeId)(gpSllgChar32PT);
    /**
     * Return a wwdW value where ww is weeks, d is days and W is W.
     * over 99 weeks and 6 days is 99+W.
     */
    void (*getAgeInWeeksAndDays)(gpSllgChar32PT);
}TimeSerNbrO0HCapiT, *TimeSerNbrO0HCapiPT;

#define TimeSerNbrHCapiT TimeSerNbrO0HCapiT
#define TimeSerNbrHCapi TimeSerNbrO0HCapi
extern TimeSerNbrHCapiT TimeSerNbrHCapi;

typedef struct TimeSerNbrLinkO0HelperInstanceApiStruct
{
    void (*saveRow)(TimeSerNbrLinkZ0HIdataPT);
    void (*trashRow)(TimeSerNbrLinkZ0HIdataPT);
    void (*toRow)(TimeSerNbrLinkZ0HIdataPT);
}TimeSerNbrLinkO0HIapiT, *TimeSerNbrLinkO0HIapiPT;
extern TimeSerNbrLinkO0HIapiT TimeSerNbrLinkO0HIapi;

typedef struct TimeSerNbrLinkZ0HelperInstanceNewStruct
{
    TimeSerNbrLinkO0HIapiPT apiP;
    TimeSerNbrLinkZ0HIdataT data;
}TimeSerNbrLinkO0HInewT, *TimeSerNbrLinkO0HInewPT;

typedef struct TimeSerNbrLinkZ0HelperClassApiStruct
{
    
}TimeSerNbrLinkO0HCapiT, *TimeSerNbrLinkO0HCapiPT;
extern TimeSerNbrLinkO0HCapiT TimeSerNbrLinkO0HCapi;

#endif /* defined(TimeSerNbrO0_h) */
/**
 */
