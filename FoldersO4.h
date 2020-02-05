//
//  FoldersO4.h (TODO in the Box tree)
//
//  Created by Robert Russell Millward on 11/22/13.
//  Copyright (c) 2013 Robert Russell Millward.
//  All rights reserved.
//

#ifndef _FoldersO4_h
#define _FoldersO4_h

#include "BufferShareO0.h"
#include "RowO2.h"
#include "DictionaryO3.h"
#include "TransactionO3.h"
#include "UserGroupO2.h"


typedef char *branchPT;
typedef char *likePT;
typedef char *pathPT;

#define folderInfoW "folderInfo"

enum folderInfoO4T
{
    FLDR_NAME = 'a',
    FLDR_MODE,
    FLDR_INODE,
    FLDR_USRID,
    FLDR_GRPID,
    FLDR_CREATTM,
    FLDR_MODFYTM
};


typedef struct FolderO4Y
{
    int (*exists)(
            branchPT branch,
                  // userGroupT group,
            likePT like,
                  // BufferShareP mgr,
            tranIxT txIX);
    void (*getFolderInfo)(
            branchPT branch,
            userGroupT group,
            likePT like,
            BufferShareP mgr,
            tranIxT txIX);
    char *(*makeFolder)(
            pathPT path,
            tranIxT txIX);
    char *(*chgFolder)(
            pathPT path,
            tranIxT txIX);
    char *(*copyJournal)(
            char *journal,
            char *from,
            char *to,
            tranIxT txIX);
    char *(*remove)(
            branchPT branch,
            tranIxT txIX);
}FolderO4X, *FolderO4XP;

#define FolderX FolderO4X
#define FolderC FolderO4C
extern FolderX FolderC;

#define initFolders initFoldersO4
extern initStatusT initFolders(void);

#endif
