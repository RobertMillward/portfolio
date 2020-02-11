//
//  TimeSerNbrO0.h
//
//  Created by Robert Russell Millward on 12/24/18.
//  Copyright © 2020 Robert Russell Millward. All rights reserved.
//
#ifndef TimeSerNbrO0_h
#define TimeSerNbrO0_h
// os
// helper api's
// data plans
#include "TimeSerNbrZ0Plan.h"
// application api's
/**
 * Managing the time and serial number values
 */
typedef const struct TimeSerNbrO0HelperClassStructure
{
    /**
     * Builds a structure of time information.
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

/**
 * Link Instance functions to saveRow, trashRow, or toRow a link.
 * Only revised links will save.
 * Validation failure information will appear in gpSllgChar64PT->theChar64
 */
typedef struct TimeSerNbrLinkO0HelperInstanceApiStruct
{
    void (*setHideRow)      (TimeSerNbrLinkZ0HIdataPT);
    void (*setUnhideRow)    (TimeSerNbrLinkZ0HIdataPT);
    void (*saveRow)         (TimeSerNbrLinkZ0HIdataPT); // Not fully implemented
    void (*toRow)           (TimeSerNbrLinkZ0HIdataPT, targetPT, massOfT, indeXPT, whoZPT, gpSllgChar64PT);
}TimeSerNbrLinkO0HIapiT, *TimeSerNbrLinkO0HIapiPT;
extern TimeSerNbrLinkO0HIapiT TimeSerNbrLinkO0HIapi;

/**
 * The "new" instance. apiPT->the api and dataT has the data.
 */
typedef struct TimeSerNbrLinkO0HelperInstanceThisStruct
{
    TimeSerNbrLinkO0HIapiPT apiP;
    TimeSerNbrLinkZ0HIdataT data;
}TimeSerNbrLinkO0AIthisT, *TimeSerNbrLinkO0AIthisPT, TimeSerNbrLinkO0AInewxT;
/**
 * The Link Class functions.
 */
typedef struct TimeSerNbrLinkO0HelperClassApiStruct
{
    TimeSerNbrLinkO0AIthisT (*newHasRow)   (abstractRowT);
    TimeSerNbrLinkO0AIthisT (*newHasFields)(timeSerNbrNodeIdT grantor,   timeSerNbrNodeIdT grntee,
                                           timeSerNbrDateTimeT,         timeSerNbrDateTimeT,
                                           gpSllgChar64PT);
}TimeSerNbrLinkO0HCapiT, *TimeSerNbrLinkO0HCapiPT;
extern TimeSerNbrLinkO0HCapiT TimeSerNbrLinkO0HCapi;

#endif /* defined(TimeSerNbrO0_h) */
/**
 */
