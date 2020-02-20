//
//  PermissionO0.h
//
//  Created by Robert R on 3/27/2019.
//  Copyright (c) 2015 Robert Russell Millward.
//  All rights reserved.
//
/**
 *
 */
#ifndef __PermissionO0__
#define __PermissionO0__
#include "PeopleGroupO0.h"
#include "AppO0.h" 
#include "RoleO0.h"
#include "PersonO0.h"
#include "TwoWayO0.h"
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
//typedef struct PermissionO0ApplicationInstanceDataStruct
//{
//    /**
//     * The PeopleGroup for this permission.
//     */
//    peopleGroupIdT peopleGroupId;
//    /**
//     * The signature of the application being operated.
//     * How many weeks old the version being run is.
//     */
//    appSigT         appSig;
//    appWeeksOldT    appWeeksOldOverRide;
//    /**
//     * The signature of the role.
//     * The level of the role this person is allowed to access.
//     */
//    roleSigT    roleSig;
//    roleLevelT  rollLevel;
//    /**
//     * The signature of the person operating the app.
//     * Their self assessed expertise level (affects prompting).
//     */
//    personSigT      personSig;
//    roleExpertiseT  roleExpertise;
//    /**
//     * Overhead variables.
//     */
//    gpTxPplGrpBatchTwoWayO0PT flagsForTwoWayEtAlP;
//    gpVersionLevelO0PT flagsForCodeVersionAndLevelP;
//    
//}PermissionO0AIdataT, *PermissionO0AIdataPT;



/**
 * Instance methods.
 * Other methods may refer to these through the extern immediately below.
 */
typedef struct PermissionO0InstanceMethodsStruct
{
    /**
     * Generate signature code from data so far.
     */
    void (* generateSignatureCode)(PermissionO0AIdataPT dataP);
    
}PermissionO0AIapiT, *PermissionO0AIapiPT;

extern PermissionO0AIapiT PermissionO0AIapi; // For easy non instance referral



typedef struct PermissionO0InstanceObjectStruct // (both data and methods)
{
    PermissionO0AIapiPT api;
    PermissionO0AIdataT data;
    
} PermissionO0AIobjT, *PermissionO0AIobjPT;
#define PermissionAIobjT PermissionO0AIobjT
#define PermissionAIobjPT PermissionO0AIobjPT
/*
 */
#pragma mark - New instance
/*
 */
extern PermissionO0AIobjT newPermissionO0(void);
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


#endif /* defined(__PermissionO0__) */
