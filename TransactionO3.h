//
//  TransactionO3.h
//
//  Created by Robert Russell Millward on 1/15/14.
//  Copyright (c) 2014 Robert Russell Millward.  All rights reserved.
//
#ifndef TransactionO3_h
#define TransactionO3_h
#include "TransactionO0.h"
//#include "InitDestroyHelperO0.h"

typedef const struct TransactionEnvO3ACapiStruct
{
    /**
     * Validate an environment name.
     */
    char* (* validateEnv)(char *envID);
    
    /**
     * First time in, set the transaction Ix based list (devOrProdPT) and count.
     * Optionally set a valid environment (devOrProdT).
     * Return the environment for the transaction else null if problems.
     */
    devOrProdT // or null if invalid
    (* setGetDevOrProd)(devOrProdT, devOrProdPT, itemCountT, gpTxPplGrpBatchTwoWayZ0PT);
    
    /**
     * Get the environment.
     */
//    char*
//    (* getDevOrProd)(gpTxPplGrpBatchTwoWayZ0PT);
    
}TransactionEnvO3HCapiT, *TransactionEnvO3HCapiPT;

#undef TransactionEnvHCapiT
#undef TransactionEnvHCapi
#define TransactionEnvHCapiT TransactionEnvO3HCapiT
#define TransactionEnvHCapi TransactionEnvO3HCapi
extern TransactionEnvHCapiT TransactionEnvHCapi;


#endif
