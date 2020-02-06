//
//  FoldersO4.h
//
//  Created by Robert Russell Millward on 11/22/13.
//  Copyright (c) 2020 Robert Russell Millward.  All rights reserved.
//
#ifndef FoldersO4_h
#define FoldersO4_h
// os
// helper api's
//#include "BufferShareO0.h"
//#include "RowO2.h"
//#include "DictionaryO3.h"
//#include "TransactionO3.h"
#include "PeopleGroupO0.h"
// data plans
#include "ArchitectureZ0Plan.h"
#include "BufferShareZ0Plan.h"
// app api's


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


typedef struct FolderO4HelperClassApiStruct
{
    int  (*exists)          (branchPT, peopleGroupIdT, likePT, BufferShareZ0dataPT, gpSllgChar64PT);
    void (*getFolderInfo)   (branchPT, peopleGroupIdT, likePT, BufferShareZ0dataPT, gpSllgChar64PT);
    char *(*makeFolder)     (pathPT, gpSllgChar64PT);
    char *(*chgFolder)      (pathPT, gpSllgChar64PT);
    char* (*copyJournal)    (char *journal, char *from, char *to, gpSllgChar64PT);
    char *(*remove)         (branchPT, gpSllgChar64PT);
}FolderO4HCapiT, *FolderO4HCapiPT;

#define FolderHCapiT FolderO4HCapiT
#define FolderHCapi FolderO4HCapi
extern FolderHCapiT FolderHCapi;

#define initFolders initFoldersO4
extern initStatusT initFolders(void);

#endif /* FoldersO4_h */
/**
 *
 */
