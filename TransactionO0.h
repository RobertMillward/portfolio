//
//  TransactionO0.h -
//
//  Created by Robert Russell Millward on 1/15/14.
//  Copyright (c) 2020 Robert Russell Millward. All rights reserved.
//
#ifndef TransactionO0_h
#define TransactionO0_h
// api
// helper api's
// data plans
#include "ArchitectureZ0Plan.h"
//#include "TransactionZ0Plan.h"


typedef const struct TransactionEnvO0HCapiStruct
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
    char*
    (* getDevOrProd)(gpTxPplGrpBatchTwoWayZ0PT);
    
}TransactionEnvO0SCapiT, *TransactionEnvO0SCapiPT;

#define TransactionEnvSCapiT TransactionEnvO0SCapiT
#define TransactionEnvSCapi TransactionEnvO0SCapi
extern TransactionEnvSCapiT TransactionEnvSCapi;



#endif /* TransactionO0_h */
/**
 * Do not change back to Z0
 */
