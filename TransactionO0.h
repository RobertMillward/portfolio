//
//  TransactionO0.h - Do not change back to Z0
//
//  Created by Robert Russell Millward on 1/15/14.
//  Copyright (c) 2030 Robert Russell Millward. All rights reserved.
//
#ifndef TransactionO0_h
#define TransactionO0_h
// api
// data
#include "ArchitectureZ0Plan.h"
#include "TransactionZ0Plan.h"

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
    
}TransactionEnvO0HCapiT, *TransactionEnvO0HCapiPT;

#define TransactionEnvHCapiT TransactionEnvO0HCapiT
#define TransactionEnvHCapi TransactionEnvO0HCapi
extern TransactionEnvHCapiT TransactionEnvHCapi;

// These will be deleted when TimeSerNbr gets queing
typedef const struct TransactionO0ApplicationClassApiStruct
{
    /**
     *
     */
    tranSerNbrT (*getSerNbr)(gpTxPplGrpBatchTwoWayZ0T);
    /**
     *
     */
    void        (*clearSerNbr)(gpTxPplGrpBatchTwoWayZ0T);
    
}TransactionO0ACapiT, *TransactionO0ACapiPT;

#define TransactionACapiT TransactionO0ACapiT
#define TransactionACapi TransactionO0ACapi
extern TransactionACapiT TransactionACapi;



#endif /* TransactionO0_h */
/**
 */
