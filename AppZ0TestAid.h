//
//  AppZ0TestAid.h
//
//  Created by Robert R on 3/5/15.
//  Copyright (c) 2015 Robert Russell Millward.
//  All rights reserved.
//

#ifndef AppZ0TestAid_h
#define AppZ0TestAid_h
#include "ArchitectureZ0.h"
//#include "TransactionZ0.h"
//#include "PermissionZ0.h"


/**
 * Instance data.
 */
//typedef struct AppZ0toInstanceDataStruct
//{
//    /**
//     * General information.
//     */
//    
//    /**
//     * Generated information.
//     */
//    appSigT sigCode;
//    
//    /**
//     * Overhead variables.
//     */
//    gpVersionLevelZ0PT flagsForCodeVersionAndLevelP;
//    
//}AppZ0AIdataT, *AppZ0AIdataPT;


/**
 * Instance methods.
 * Other methods may refer to these through the extern immediately below.
 */
typedef struct AppZ0AppInstanceMethodsStruct
{
    /**
     * Generate signature code from data so far.
     */
    void (* generateSignatureCode)(AppZ0AIdataPT dataP);
    /**
     *
     */
    //void (* openRead)(fileNmPT file, AppZ0toIPT dataP);
    /**
     *
     */
    //void (* read)(int length, char *buffer, AppZ0toIPT dataP);
    /**
     *
     */
    //Sint (* isAtEof)(AppZ0toIPT dataP);
    
}AppZ0AIapiT, *AppZ0AIapiPT;

extern AppZ0AIapiT AppZ0AIapi;



typedef struct AppZ0goInstanceStruct // (both data and methods)
{
    AppZ0AIapiPT api;
    AppZ0AIdataT data;
    
} AppZ0AInewT, *AppZ0AInewPT;
#define AppAInewT AppZ0AInewT
#define AppAInewPT AppZ0AInewPT
/*
 */
#pragma mark - New instance
/*
 */
extern AppZ0AInewT newAppZ0(void);
/*
 */
#pragma mark - Class Methods
/*
 */
typedef struct AppZ0ClassMethodsStruct
{
    /**
     *
     */
    void (* doNothing)(void);
    
    
}AppZ0ACapiT, *AppZ0ACapiPT;

extern AppZ0ACapiT AppZ0ACapi;


#endif /* defined(__AppZ0__) */
