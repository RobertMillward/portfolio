//
//  AuthAndAuthO8.h - A thread safe authentication and authorization management learning library
//
//  Created by Robert R on 10/31/14.
//  Copyright (c) 2019 Robert Russell Millward. All rights reserved.
//
#ifndef AuthAndAuthO8_h
#define AuthAndAuthO8_h
//#include <stdio.h>
#include "AuthAndAuthO8Plan.h"

typedef struct AuthAndAuthO8AppClassApiStruct
{
    /**
     * At my location produce a generated Authentication head key.
     */
    void (* newRow)(char* newRowP, massOfT, AuthAuthZ0AIEntityT, whoZPT, gpTxPplGrpBatchTwoWayZ0PT);
    /**
     *
     */
    int (*userHasStepInGroup)(char *userID,
                              char *groupID,
                              char *envrID,
                              char *appID,
                              char *featID,
                              char *stepID);
    
    
}AuthAndAuthO8ACapiT, *AuthAndAuthO8ACapiPT;

extern AuthAndAuthO8ACapiT AuthAndAuthO8ACapi;

#endif /* defined(AuthAndAuthO8_h) */
/**
 * Authentication and Authorization
 */

