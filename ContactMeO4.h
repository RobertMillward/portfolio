//
//  ContactMeO4.h - A thread safe library to store and share contact information.
//
//  Created by Robert R on 12/21/19.
//  Copyright (c) 2020 Robert Russell Millward.  All rights reserved.
//
#ifndef ContactMeO4_h
#define ContactMeO4_h
//#include "ArchitectureZ0.h"
#include "ContactMeZ0Plan.h"

/*
 */
#pragma mark - Instance Api
/*
 */
typedef struct ContactMeO4AppInstanceApiStructure
{
    void    (*saveRow)(ContactMeZ0AIdataPT);
    void    (*trashRow)(ContactMeZ0AIdataPT);
    void    (*toRow)(ContactMeZ0AIdataPT, targetPT, massOfT, indeXPT, whoZPT, gpTxPplGrpBatchTwoWayZ0PT);
    
}ContactMeO4AIapiT, *ContactMeO4AIapiPT;
extern ContactMeO4AIapiT ContactMeO4AIapi;


typedef struct ContactMeLinkO4AppInstanceApiStructure
{
    void    (*saveRow)(ContactMeLinkZ0AIdataPT);
    void    (*trashRow)(ContactMeLinkZ0AIdataPT);
    void    (*toRow)(ContactMeLinkZ0AIdataPT, targetPT, massOfT, indeXPT, whoZPT, gpTxPplGrpBatchTwoWayZ0PT);
    
}ContactMeLinkO4AIapiT, *ContactMeLinkO4AIapiPT;
extern ContactMeLinkO4AIapiT ContactMeLinkO4AIapi;


typedef struct ContactMeStatusO4AppInstanceApiStructure
{
    void    (*saveRow)(ContactMeStatusZ0AIdataPT);
    void    (*trashRow)(ContactMeStatusZ0AIdataPT);
    void    (*rowOf)(ContactMeStatusZ0AIdataPT, targetPT, massOfT, indeXPT, whoZPT, gpTxPplGrpBatchTwoWayZ0PT);
    
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
    
} ContactMeO4AInewT, *ContactMeO4AInewPT;

typedef struct ContactMeLinkO4AppNewInstanceStruct // (both data and methods)
{
    ContactMeLinkO4AIapiPT apiP;
    ContactMeLinkZ0AIdataT data;
    
} ContactMeLinkO4AInewT, *ContactMeLinkO4AInewPT;

typedef struct ContactMeStatusO4AppNewInstanceStruct // (both data and methods)
{
    ContactMeStatusO4AIapiPT apiP;
    ContactMeStatusZ0AIdataT data;
    
} ContactMeStatusO4AInewT, *ContactMeStatusO4AInewPT;

/*
 */
#pragma mark - Class Api
/*
 */
typedef struct ContactMeO4AppClassApiStruct
{
    ContactMeO4AInewT (*newForInsert)(abstractRowT);
    ContactMeO4AInewT (*newToView)(abstractRowT);
    
}ContactMeO4ACapiT, *ContactMeO4ACapiPT;
#define ContactMeACapiT ContactMeO4ACapiT
#define ContactMeACapi  ContactMeO4ACapi
extern ContactMeACapiT ContactMeACapi;

typedef struct ContactMeLinkO4AppClassApiStruct
{
    ContactMeLinkO4AInewT (*newForInsert)(abstractRowT);
    ContactMeLinkO4AInewT (*newToView)(abstractRowT);
    
}ContactMeLinkO4ACapiT, *ContactMeLinkO4ACapiPT;
#define ContactMeLinkACapiT ContactMeLinkO4ACapiT
#define ContactMeLinkACapi  ContactMeLinkO4ACapi
extern ContactMeLinkACapiT ContactMeLinkACapi;

typedef struct ContactMeStatusO4AppClassApiStruct
{
    ContactMeO4AInewT (*newForInsert)(abstractRowT);
    ContactMeO4AInewT (*newToView)(abstractRowT);
    
}ContactMeStatusO4ACapiT, *ContactMeStatusO4ACapiPT;
#define ContactMeStatusACapiT ContactMeStatusO4ACapiT
#define ContactMeStatusACapi  ContactMeStatusO4ACapi
extern ContactMeStatusACapiT ContactMeStatusACapi;

#endif /* defined(ContactMeO4_h) */
/**
 FEATURED 12/18/19
 */
