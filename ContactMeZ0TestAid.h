//
//  ContactMeZ0TestAid.h
//
//  Created by Robert Russell Millward on 1/31/20.
//  Copyright © 2020 Robert Russell Millward. All rights reserved.
//
#ifndef ContactMeZ0TestAid_h
#define ContactMeZ0TestAid_h
// os
#include <stdio.h>
// helper api's
// data plans
#include "ArchitectureZ0Plan.h"
// application api's
// quality

/**
 * Note 1: InstanceWarnings contains the count of generated prople
*/
typedef struct ContactMeZ0QualityClassApiStruct
{
    ErrorWarnCountT (*testSupply)(lineNbrT); // see note 1 above
}cnctMeDGZ0QCapiT, * cnctMeDGZ0QCapiPT;

extern cnctMeDGZ0QCapiT cnctMeDGZ0QCapi;

#endif /* ContactMeZ0TestAid_h */
/**
 *
 */
