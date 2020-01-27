//
//  JournalZ3TestAid.h
//
//  Created by Robert Russell Millward on 9/26/13.
//  Copyright (c) 2013 Robert Russell Millward.  All rights reserved.
//
#ifndef JournalZ3TestAid_h
#define JournalZ3TestAid_h

#include "JournalO3.h"


#pragma mark - the communication

typedef struct JnlAidZ3ExpectS
{
    PermissionZ0AIdataPT permissionP;
    
    ErrorWarnCountT global;
    ErrorWarnCountT testAid;
    
    char* isConsistant;
    char openMode[4];
    Zint isAtEOF;
    Zint operations;
    Zlng fileSizeB4;
    Zlng fileSizeAfter;
    char* theOffender;
    
} JnlAidQ3ExpectT, *JnlAidQ3ExpectPT;


/**
 * The Q class is for Quality checking.
 * Journals (plural) is for the class and Journal (singular) is for the instance.
 * InitDestroyHelper.destroyAll() is the class cleanup
 */
typedef struct JnlAidO3Y
{
    JnlAidQ3ExpectT (*getInitialExpect)(void);
    char* (*getNewJournalForTest)(JournalZ3AIdataPT  whereItGoes,           lineNbrT, JnlAidQ3ExpectPT);
    char* (*openReadForTest)    (JournalZ3AIdataPT this, fileNmPT fileName, lineNbrT, JnlAidQ3ExpectPT);
    char* (*readForTest)        (JournalZ3AIdataPT this, char* buffer,      lineNbrT, JnlAidQ3ExpectPT);
    char* (*setTruncateForTest) (JournalZ3AIdataPT this,                    lineNbrT, JnlAidQ3ExpectPT);
    char* (*openWriteForTest)   (JournalZ3AIdataPT this, fileNmPT fileName, lineNbrT, JnlAidQ3ExpectPT);
    char* (*writeForTest)       (JournalZ3AIdataPT this, char* buffer,      lineNbrT, JnlAidQ3ExpectPT);
    char* (*closeForTest)       (JournalZ3AIdataPT this,                    lineNbrT, JnlAidQ3ExpectPT);
    
}JnlAidO3X, *JnlAidO3XP;
extern JnlAidO3X JnlAidO3Q;
#define JnlAidQ JnlAidO3Q



typedef struct JnlsAidO3Y
{
    void (* initPath)(pathPT path, gpTxPplGrpBatchTwoWayZ0PT infoP);
    initStatusT (* initJournals)(gpTxPplGrpBatchTwoWayZ0PT infoP);
    //void (*destroyAll)(gpTxPplGrpBatchTwoWayZ0PT approvedParmNameP);
}JnlsAidO3XT, *JnlsAidO3XPT;

extern JnlsAidO3XT JnlsAidO3Q;
#define JnlsAidQ JnlsAidO3Q

#endif // JournalZ3TestAid.h
/**
 */
