//
//  PermissionZ0TestAid.h
//  2020Apr21Dev
//
//  Created by Robert R on 3/27/2019.
//  Copyright (c) 2020 Robert Russell Millward.  All rights reserved.
//
/**
 *
 */
#ifndef PermissionZ0TestAid_h
#define PermissionZ0TestAid_h
// api
// data
#include "ArchitectureZ0Plan.h"
//#include "PeopleGroupZ0.h"
//#include "AppZ0.h"
//#include "RoleZ0.h"
//#include "PersonZ0.h"
//#include "TwoWayZ0.h"
/*
 */
#pragma mark - init and destroy.
/*
 */

/*
 */
#pragma mark - The instance
/*
 */



/**
 * Instance methods.
 * Other methods may refer to these through the extern immediately below.
 */
typedef struct PermissionZ0InstanceMethodsStruct
{
    /**
     * Generate signature code from data so far.
     */
    void (* generateSignatureCode)(PermissionZ0AIdataPT dataP);
    
}PermissionZ0AIapiT, *PermissionZ0AIapiPT;

extern PermissionZ0AIapiT PermissionZ0AIapi; // For easy non instance referral



typedef struct PermissionZ0InstanceNewStruct // (both data and methods)
{
    PermissionZ0AIapiPT api;
    PermissionZ0AIdataT data;
    
} PermissionZ0AInewT, *PermissionZ0AInewPT;
#define PermissionAInewT PermissionZ0AInewT
#define PermissionAInewPT PermissionZ0AInewPT
/*
 */
#pragma mark - New instance
/*
 */
extern PermissionZ0AInewT newPermissionZ0(void);
/*
 */
#pragma mark - Class Methods
/*
 */
typedef struct PermissionZ0ClassMethodsStruct
{
    /**
     *
     */
    void (* doNothing)(void);
    
    
}PermissionZ0ACapiT, *PermissionZ0ACapiPT;

extern PermissionZ0ACapiT PermissionZ0C;


#endif /* defined(PermissionZ0TestAid_h) */
