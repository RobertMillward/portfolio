//
//  AuthAndAuthZ8TestAid.c
//
//  Created by Robert Russell Millward on 10/4/19.
//  Copyright (c) 2019 Robert Russell Millward.  All rights reserved.
//

#include <stdio.h>
#include <libc.h>
#include <string.h>
#include "AuthAndAuthZ8TestAid.h"
#include "TestAidZ0.h"
/**
 * The api call interceptors
 */
void
AuthAuthO8_new_tx99(char* newAuthP, massOfT massOf, AuthAuthZ0AIEntityT forType, whoZPT whoZP,
                      gpTxPplGrpBatchTwoWayZ0PT twoWayEtAlP, lineNbrT lineNbr)
{
    AuthAndAuthO8ACapi.newRow(newAuthP, massOf, forType, whoZP, twoWayEtAlP);
}



/**
 * The tests.
 */
ErrorWarnCountT
AuthAuthO8CheckSizes(lineNbrT driverLineNbr)
{
    ErrorWarnCountT ewc = {0, 0, 0, 0};
    
    char here[200];
    whoZPT whoZ = "somemadeup";
    
    AuthAuthO8_new_tx99(here, sizeof(here), PERSON_ENTITY_AA, whoZ, &TestAidZ0QCdata.twoWay, __LINE__);
    if(TestAidQCapi.putTestInts((int)strlen(here), 40, __LINE__) != 0)
    {
        ewc.classErrors++;
    }
    
    return ewc;
}



/**
 * The interface structure.
 */
AuthAndAuthO8QCapiT AuthAndAuthO8QCapi =
{
    /**
     * Instrumentable calls.
     */
    AuthAuthO8_new_tx99,
    /**
     * Test calls
     */
    AuthAuthO8CheckSizes
};


// END AuthAndAuthZ8TestAid.c
/**
 */