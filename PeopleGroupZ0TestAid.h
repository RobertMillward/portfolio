//
//  PeopleGroupZ0TestAid.h
//
//  Created by Robert Russell Millward on 1/31/20.
//  Copyright © 2020 Robert Russell Millward. All rights reserved.
//
#ifndef PeopleGroupZ0TestAid_h
#define PeopleGroupZ0TestAid_h
// os
// helper api's
// data plans
#include "PersonZ0Plan.h"
// application api's
// quality
#include "TestAidZ0.h"


typedef struct PeopleGroupZ0QualityClassApiStruct
{
    ErrorWarnCountT (*newQ)(lineNbrT);
    /**
     *
     */
    ErrorWarnCountT (*fakeTestQ)(lineNbrT);
    
    
}PeopleGroupZ0QCapiT, *PeopleGroupZ0QCapiPT;

extern PeopleGroupZ0QCapiT PeopleGroupZ0QCapi;

#endif /* PeopleGroupZ0TestAid_h */
