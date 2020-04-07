//
//  AuthAndAuthO8.h - A thread safe authentication and authorization management learning library
//  2020Apr21Dev
//
//  Created by Robert R on 10/31/14.
//  Copyright (c) 2020 Robert Russell Millward. All rights reserved.
//
#ifndef AuthAndAuthO8_h
#define AuthAndAuthO8_h
// os
//#include <stdio.h>
// helper and service api's
// data plans
#include "AuthAndAuthZ8Plan.h"
// other api's

typedef struct AuthAndAuthO8AppClassApiStruct
{
    /**
     * At my location produce a generated Authentication head key.
     */
    void (* newRow)(char* newRowP, massOfT, AuthAuthZ0AIEntityT, whoZPT, gpSllgChar64PT);
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

#endif /* AuthAndAuthO8_h */
/**
 * Authentication and Authorization
 */

