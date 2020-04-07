//
//  PermissionO0.h
//  2020Apr21Dev
//
//  Created by Robert R on 3/27/2019.
//  Copyright (c) 2020 Robert Russell Millward.  All rights reserved.
//
#ifndef PermissionO0_h
#define PermissionO0_h
// os
// helper and server spi's
// data plans
#include "PermissionZ0Plan.h"
// other api's
#include "PeopleGroupO4.h"
#include "AppO4.h" 
#include "RoleO0.h"
#include "PersonO4.h"
//#include "TwoWayO0.h"



/**
 * Instance methods.
 * Other methods may refer to these through the extern immediately below.
 */
typedef struct PermissionO0InstanceMethodsStruct
{
    /**
     * Generate signature code from data so far.
     */
    void (* generateSignatureCode)(PermissionZ0AIdataPT dataP);
    
}PermissionO0AIapiT, *PermissionO0AIapiPT;

extern PermissionO0AIapiT PermissionO0AIapi; // For easy non instance referral



typedef struct PermissionO0ApplicationThisStruct // (both data and methods)
{
    PermissionO0AIapiPT api;
    PermissionZ0AIdataT data;
    
} PermissionO0AIthisT, *PermissionO0AIthisPT;
#define PermissionAIthisT PermissionO0AIthisT
#define PermissionAIthisPT PermissionO0AIthisPT
/*
 */
#pragma mark - New instance
/*
 */
extern PermissionO0AIthisT newPermissionO0(void);
/*
 */
#pragma mark - Class Methods
/*
 */
typedef struct PermissionO0ClassMethodsStruct
{
    /**
     *
     */
    void (* doNothing)(void);
    
    
}PermissionO0ACapiT, *PermissionO0ACapiPT;

extern PermissionO0ACapiT PermissionO0C;


#endif /* PermissionO0_h */
/**
 *
 */
