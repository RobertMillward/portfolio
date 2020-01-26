//
//  AuthAndAuthZ8TestAid.h
//
//  Created by Robert Russell Millward on 12/14/19.
//  Copyright (c) 2019 Robert Russell Millward. All rights reserved.
//
#ifndef AuthAndAuthZ8TestAid_h
#define AuthAndAuthZ8TestAid_h
#include "AuthAndAuthO8.h"

/**
 * A thread safe library to support the stages of Row creation.
 */
typedef const struct AuthAndAuthO8QCapiS
{
    // These have line number unlike O8.h
    void (* newRow)(char* newRowP, massOfT, AuthAuthZ0AIEntityT, whoZPT, gpTxPplGrpBatchTwoWayZ0PT, lineNbrT);
    
    // These have line number unlike O8.h
    
    
    /**
     * Tests to certify that the library won't crash for:
     *
     * a missing target or source argument
     * a source containing FLDSEP_ROW or ROWSEP_ROW
     * a field Letter of NUL_ARC, EQ_ARC, FLDSEP_ROW or ROWSEP_ROW
     */
    ErrorWarnCountT (*checkSizes)(lineNbrT);
//    ErrorWarnCountT (*letterTests)(lineNbrT);
//    ErrorWarnCountT (*sourceTests)(lineNbrT);
    
}AuthAndAuthO8QCapiT, *AuthAndAuthO8QCapiPT;

extern AuthAndAuthO8QCapiT AuthAndAuthO8QCapi;

/**
 * Additional Versons api will go here.
 */

#endif /* defined(AuthAndAuthZ8TestAid_h) */
/**
 */
