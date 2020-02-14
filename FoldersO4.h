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

// temporary, move to plan then move out
#define IDH_DO_HERE_INIT "Do"
#define IDH_IS_DONE_STEP "Done"

typedef char *branchPT;
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


typedef struct FoldersO4HelperClassApiStruct
{
    int   (*exists)         (branchPT, peopleGroupIdT, likePT, BufferShareZ0HIdataPT, gpSllgChar64PT);
    void  (*getInfo)        (branchPT, peopleGroupIdT, likePT, BufferShareZ0HIdataPT, gpSllgChar64PT);
    char* (*make)           (pathPT, gpSllgChar64PT);
    char* (*change)         (pathPT, gpSllgChar64PT);
    char* (*copyJournal)    (char *journal, char *from, char *to, gpSllgChar64PT);
    char* (*remove)         (branchPT, gpSllgChar64PT);
}FoldersO4HCapiT, *FoldersO4HCapiPT;

#define FoldersHCapiT FoldersO4HCapiT
#define FoldersHCapi FoldersO4HCapi
extern FoldersHCapiT FoldersHCapi;

#endif /* FoldersO4_h */
/**
 *
 */
