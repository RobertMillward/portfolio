//
//  Message8.h
//  WikiDbLib
//
//  Created by Robert R on 10/30/14.
//  Copyright (c) 2014 Robert Russell Millward. All rights reserved.
//

#ifndef __WikiDbLib__Message8__
#define __WikiDbLib__Message8__

#include "Row.h"



// Caller's message is like this:
// (Except for the ENVID<
//  all subcontents are this length.)
#define MSG_INFO_LEN 7

// APPIDXX, including MSG_QUIT
// FEATIDX, including MSG_SHUTDOWN, MSG_EMRGNCY
// STEPIDX, including MSG_COMMIT, MSG_ROLLBACK
// GROUPID, (user, group, role permission sel)
// ROLEIDX,
// USERIDX,
// ONEMORE, (no use assigned)
// ENVIDXX  (environment selector)






#define MSG_QUIT     "SHUTDWN"
// sub messages to QUIT
#define MSG_SHUTDOWN "VRYSOON"
#define MSG_EMRGNCY  "IMMDTLY"

// Options for the final STEPID of a transaction.
#define MSG_COMMIT   "COMMMIT"
#define MSG_ROLLBACK "ROLLBAK"


typedef struct Message8Y
{
    char *ctl;
    
    char *(*getAppID)(struct Message8Y *this);
    char *(*getFeatureID)(struct Message8Y *this);
    char *(*getStepID)(struct Message8Y *this);
    void  (*setAppID)(struct Message8Y *this,
                      char *id);
    void  (*setFeatureID)(struct Message8Y *this,
                          char *id);
    void  (*setStepID)(struct Message8Y *this,
                       char *id);
    
    char *(*getGroupID)(struct Message8Y *this);
    char *(*getRoleID)(struct Message8Y *this);
    char *(*getUserID)(struct Message8Y *this);
    char *(*getEnvrID)(struct Message8Y *this);
    void  (*setGroupID)(struct Message8Y *this,
                        char *id);
    void  (*setRoleID)(struct Message8Y *this,
                       char *id);
    void  (*setUserID)(struct Message8Y *this,
                       char *id);
    void  (*setEnvrID)(struct Message8Y *this,
                       char *id);
    
    void  (*getOut)(struct Message8Y *this);
    
}Message8, *Message8P;

// Side-effect: message is left in-place and
// interesting features are null terminated.
// Call getOut() at completion of processing
// to undo nulls.
// The Message8 contents is in this Row section.
#define MSG_INFO_LTTR ROW_LAST_VALUE
extern Message8 newMessage8(char *msgCtlField);


#endif /* defined(__WikiDbLib__Message8__) */
