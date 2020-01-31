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

/**
 * Instance methods.
 */
typedef struct AppO4ApplicationInstanceMethodsStruct
{
    
}AppO4AIapiT, *AppO4AIapiPT;

extern AppO4AIapiT AppO4AIapi;



typedef struct AppO4NewInstanceStruct // (both data and methods)
{
    AppO4AIapiPT apiP;
    AppZ0AIdataT data;
    
} AppO4AInewT, *AppO4AInewPT;
#define AppAInewT AppZ0AInewT
#define AppAInewPT AppZ0AInewPT

/*
 */
#pragma mark - Class Methods
/*
 */
typedef struct AppO4ApplicationClassMethodsStruct
{
    /**
     *
     */
    AppO4AInewT (*newAppAI)(appNameT);
    
    void        (*generateSignatureCode)(AppZ0AIdataPT);
    
    
}AppO4ACapiT, *AppO4ACapiPT;

extern AppO4ACapiT AppO4ACapi;


#endif /* AppO4_h */
/**
 *
 */
