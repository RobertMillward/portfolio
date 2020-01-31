//
//  ContactMeO0.h - A thread safe library to store and share contact information.
//
//  Created by Robert R on 12/21/19.
//  Copyright (c) 2020 Robert Russell Millward.  All rights reserved.
//
#ifndef ContactMeO4_h
#define ContactMeO4_h
//#include "ArchitectureZ0.h"
#include "ContactMeZ0Plan.h"

typedef struct ContactMeO0AppInstanceApiStructure
{
    /**
     *
     * sourcePT is pointer to the whoZ informtion
     */
    void
    (* toRowContact)(ContactMeZ0AIdataPT, targetPT, massOfT, indeXPT, whoZPT, gpTxPplGrpBatchTwoWayZ0PT);
    
    void
    (* toRowLink)(ContactMeZ0AIlinkPT, targetPT, massOfT, indeXPT, whoZPT, gpTxPplGrpBatchTwoWayZ0PT);
    
    void
    (* toRowStatus)(ContactMeZ0AIstatusPT, targetPT, massOfT, indeXPT, whoZPT, gpTxPplGrpBatchTwoWayZ0PT);
    
    
}ContactMeO0AIapiT, *ContactMeO0AIapiPT;

#define ContactMeAIapiT ContactMeO0AIapiT
#define ContactMeAIapi  ContactMeO0AIapi
extern const ContactMeAIapiT ContactMeAIapi;

#endif /* defined(ContactMeO4_h) */
/**
 FEATURED 12/18/19
 */
