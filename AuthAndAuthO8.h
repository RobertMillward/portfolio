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

typedef struct AuthAndAuthO8ServiceClassApiStruct
{
    /**
     * At my location produce a generated Authentication head key.
     */
    void (* newRow)(char* newRowP, massOfT, AuthAuthEntityZ0SItypeT, whoZPT, gpSllgChar64PT);
    /**
     *
     */
    int (*userHasStepInGroup)(char *userID,
                              char *groupID,
                              char *envrID,
                              char *appID,
                              char *featID,
                              char *stepID);
    
    
}AuthAndAuthO8SCapiT, *AuthAndAuthO8SCapiPT;

extern AuthAndAuthO8SCapiT AuthAndAuthO8SCapi;

#endif /* AuthAndAuthO8_h */
/**
 * Authentication and Authorization
 * Gets messages and validates information then builds and executes the step.
 */

