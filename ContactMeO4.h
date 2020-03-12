//
//  ContactMeO4.h - A thread safe library to store and share contact information.
//  2020Apr02Dev
//
//  Created by Robert R on 12/21/19.
//  Copyright (c) 2020 Robert Russell Millward.  All rights reserved.
//
#ifndef ContactMeO4_h
#define ContactMeO4_h
// os
// helper and service api's
// data plans
#include "ContactMeZ0Plan.h"
// other api's

/*
 */
#pragma mark - Instance Api
/*
 */
typedef struct ContactMeO4AppInstanceApiStructure
{
    void    (*saveRow)(ContactMeZ0AIdataPT);
    void    (*trashRow)(ContactMeZ0AIdataPT);
    void    (*toRow)(ContactMeZ0AIdataPT, targetPT, massOfT, indeXPT, whoZPT, gpSllgChar64PT);
    
}ContactMeO4AIapiT, *ContactMeO4AIapiPT;
extern ContactMeO4AIapiT ContactMeO4AIapi;


typedef struct ContactMeLinkO4AppInstanceApiStructure
{
    void    (*saveRow)(ContactMeLinkZ0AIdataPT);
    void    (*trashRow)(ContactMeLinkZ0AIdataPT);
    void    (*toRow)(ContactMeLinkZ0AIdataPT, targetPT, massOfT, indeXPT, whoZPT, gpSllgChar64PT);
    
}ContactMeLinkO4AIapiT, *ContactMeLinkO4AIapiPT;
extern ContactMeLinkO4AIapiT ContactMeLinkO4AIapi;


typedef struct ContactMeStatusO4AppInstanceApiStructure
{
    void    (*saveRow)(ContactMeStatusZ0AIdataPT);
    void    (*trashRow)(ContactMeStatusZ0AIdataPT);
    void    (*rowOf)(ContactMeStatusZ0AIdataPT, targetPT, massOfT, indeXPT, whoZPT, gpSllgChar64PT);
    
}ContactMeStatusO4AIapiT, *ContactMeStatusO4AIapiPT;
extern ContactMeStatusO4AIapiT ContactMeStatusO4AIapi;

/*
 */
#pragma mark - New Instance
/*
 */
typedef struct ContactMeO4AppNewInstanceStruct // (both data and methods)
{
    ContactMeO4AIapiPT apiP;
    ContactMeZ0AIdataT data;
    
} ContactMeO4AIthisT, *ContactMeO4AIthisPT;

typedef struct ContactMeLinkO4AppNewInstanceStruct // (both data and methods)
{
    ContactMeLinkO4AIapiPT apiP;
    ContactMeLinkZ0AIdataT data;
    
} ContactMeLinkO4AIthisT, *ContactMeLinkO4AIthisPT;

typedef struct ContactMeStatusO4AppNewInstanceStruct // (both data and methods)
{
    ContactMeStatusO4AIapiPT apiP;
    ContactMeStatusZ0AIdataT data;
    
} ContactMeStatusO4AIthisT, *ContactMeStatusO4AIthisPT;

/*
 */
#pragma mark - Class Api
/*
 */
typedef struct LongLat04AppClassApiStruct
{
    /**
     * latitude and longitude are provided in decimal strings as -47.228 or 57.914.
     */
    void    (*ofLatLong)(longLatPT, char* latitude, char* longitude);
    /**
     * the distance between two points given in
     */
    double  (*distance) (longLatPT place, longLatPT dest);
    
}LongLatO4ACapiT;
extern LongLatO4ACapiT LongLatO4ACapi;


typedef struct ContactMeO4AppClassApiStruct
{
    ContactMeO4AIthisT (*newHasKey)(abstractRowT);
    ContactMeO4AIthisT (*newNoKey)(abstractRowT);
    ContactMeO4AIthisT (*newHasFields)(timeSerNbrNodeIdT,
                                      dataTypeT type, orderT, dataTypeT subType, contactInfoT,
                                      gpSllgChar64PT);
    
    
}ContactMeO4ACapiT, *ContactMeO4ACapiPT;
#define ContactMeACapiT ContactMeO4ACapiT
#define ContactMeACapi  ContactMeO4ACapi
extern ContactMeACapiT ContactMeACapi;

typedef struct ContactMeLinkO4AppClassApiStruct
{
    ContactMeLinkO4AIthisT (*newHasKey)(abstractRowT);
    ContactMeLinkO4AIthisT (*newNoKey)(abstractRowT);
    ContactMeLinkO4AIthisT (*newHasFields)(abstractRowT, int, gpSllgChar64PT);
    
}ContactMeLinkO4ACapiT, *ContactMeLinkO4ACapiPT;
#define ContactMeLinkACapiT ContactMeLinkO4ACapiT
#define ContactMeLinkACapi  ContactMeLinkO4ACapi
extern ContactMeLinkACapiT ContactMeLinkACapi;

typedef struct ContactMeStatusO4AppClassApiStruct
{
    ContactMeStatusO4AIthisT (*newHasKey)(abstractRowT);
    ContactMeStatusO4AIthisT (*newNoKey)(abstractRowT);
    ContactMeStatusO4AIthisT (*newHasFields)(abstractRowT, int, gpSllgChar64PT);
    
}ContactMeStatusO4ACapiT, *ContactMeStatusO4ACapiPT;
#define ContactMeStatusACapiT ContactMeStatusO4ACapiT
#define ContactMeStatusACapi  ContactMeStatusO4ACapi
extern ContactMeStatusACapiT ContactMeStatusACapi;

#endif /* ContactMeO4_h */
/**
 FEATURED 12/18/19
 */
