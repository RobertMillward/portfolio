//
//  AppO4.h
//
//  Created by Robert Russell Millward on 1/29/20.
//  Copyright © 2020 Robert Russell Millward. All rights reserved.
//
#ifndef AppO4_h
#define AppO4_h
// os
// helper api's
// data plans
#include "AppZ0Plan.h"
// app api's

/*
 */
#pragma mark - Instance Api
/*
 */
typedef struct AppO4ApplicationInstanceApiStruct
{
    void    (*saveRow)(void);
    void    (*trashRow)(void);
    void        (*rowOf)    (appNameT);
    void        (*generateSignatureCode)(AppZ0AIdataPT);
}AppO4AIapiT, *AppO4AIapiPT;
extern AppO4AIapiT AppO4AIapi;


/*
 */
#pragma mark - New Instance
/*
 */
typedef struct AppO4NewInstanceStruct // (both data and methods)
{
    AppO4AIapiPT apiP;
    AppZ0AIdataT data;
    
} AppO4AInewT, *AppO4AInewPT;

/*
 */
#pragma mark - Class Api
/*
 */
typedef struct AppO4ApplicationClassApiStruct
{
    /**
    * The sources for new instances are to create from scratch and to retrieve from the repository.
    */
    AppO4AInewT (*newForInsert)(abstractRowT);
    AppO4AInewT (*newToView)(abstractRowT);
    
}AppO4ACapiT, *AppO4ACapiPT;
#define AppACapiT AppO4ACapiT
#define AppACapi AppO4ACapi
extern AppACapiT AppACapi;


#endif /* AppO4_h */
/**
 *
 */
