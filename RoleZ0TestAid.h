//
//  RoleZ0TestAid.h
//
//  Created by Robert R on 3/27/2019.
//  Copyright (c) 2015 Robert Russell Millward.
//  All rights reserved.
//
/**
 *
 */
#ifndef RoleZ0TestAid_h
#define RoleZ0TestAid_h
#include "RoleZ0Plan.h"
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
typedef struct RoleZ0ApplicationInstanceMethodsStruct
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

typedef struct RoleZ0goInstanceStruct // (both data and methods)
{
    RoleZ0AIapiPT api;
    RoleZ0AIdataT data;
    
} RoleZ0AInewT, *RoleZ0AInewPT;
#define RoleAInewT RoleZ0AInewT
#define RoleAInewPT RoleZ0AInewPT
/*
 */
#pragma mark - New instance
/*
 */
extern RoleZ0AInewT newRoleZ0(void);
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



#endif /* defined(RoleZ0TestAid_h) */
