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
#include "ArchitectureZ0Plan.h"
#include "RowZ0Plan.h"
// app api's
// application api's


/*
 */
#pragma mark - instance api
/*
 */
typedef struct AppO4ApplicationInstanceApiStructure
{
    //void    (*getSignature) (AppZ0AIdataPT);
    //void    (*getNode)      (AppZ0AIdataPT);
    //void    (*getGroupSize) (AppZ0AIdataPT);
    
    void    (*hide)  (AppZ0AIdataPT);
    void    (*unhide)(AppZ0AIdataPT);
    void    (*save)  (AppZ0AIdataPT);
    void    (*rowOf) (AppZ0AIdataPT,
                      targetPT targetP, massOfT massOf,
                      indeXPT indeXP, whoZPT whoZP,
                      gpSllgChar64PT gp64P);
    
}AppO4AIapiT, *AppO4AIapiPT;

// extern AppO4AIapiT AppO4AIapi; // available through the instance.apiP

/*
 */
#pragma mark - New instance
/*
 */
typedef struct AppO4ApplicationInstanceNewStructure
{
    AppO4AIapiPT apiP;
    AppZ0AIdataT data;
    
}AppO4AInewT, *AppO4AInewPT;


/*
 */
#pragma mark - Class Api
/*
 */
typedef struct AppO4ApplicationClassApiStructure
{
    /**
     *
     */
    AppO4AInewT (*fromRow)(abstractRowT);
    /**
     *
     */
    AppO4AInewT (*fromFields)(appIdT, gpSllgChar64PT);
    
}AppO4ACapiT, *AppO4ACapiPT;
#define AppACapiT AppO4ACapiT
#define AppACapi AppO4ACapi
extern AppACapiT AppACapi;


#endif /* AppO4_h */
/**
 *
 */
