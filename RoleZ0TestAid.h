//
//  RoleZ0TestAid.h
//  2020Apr21Dev
//
//  Created by Robert R on 3/27/2019.
//  Copyright (c) 2020 Robert Russell Millward.  All rights reserved.
//]
#ifndef RoleZ0TestAid_h
#define RoleZ0TestAid_h
// os
// helper and service api's
// data plans
#include "RoleZ0Plan.h"
// other api's

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
typedef struct RoleZ0ApplicationInstanceApiStruct
{
    /**
     * Generate signature code from data so far.
     */
    void (* generateSignatureCode)(RoleZ0AIdataPT dataP);
    /**
     *
     */
    //void (* openRead)(fileNmPT file, RoleZ0toIPT dataP);
    /**
     *
     */
    //void (* read)(int length, char *buffer, RoleZ0toIPT dataP);
    /**
     *
     */
    //Sint (* isAtEof)(RoleZ0toIPT dataP);
    
}RoleZ0AIapiT, *RoleZ0AIapiPT;

extern RoleZ0AIapiT RoleZ0AIapi; // For easy non instance referral

typedef struct RoleZ0ApplicationInstanceThisStruct // (both data and methods)
{
    RoleZ0AIapiPT api;
    RoleZ0AIdataT data;
    
} RoleZ0AIthisT, *RoleZ0AIthisPT;
#define RoleAIthisT RoleZ0AIthisT
#define RoleAIthisPT RoleZ0AIthisPT

/*
 */
#pragma mark - New instance
/*
 */
//extern RoleZ0AIthisT newRoleZ0(void);
/*
 */
#pragma mark - Class Methods
/*
 */
typedef struct RoleZ0ApplicationClassMethodsStruct
{
    /**
     *
     */
    void (* doNothing)(void);
    
    
}RoleZ0ACapiT, *RoleZ0ACapiPT;

extern RoleZ0ACapiT RoleZ0ACapi;



#endif /* RoleZ0TestAid_h */
/**
 *
 */
