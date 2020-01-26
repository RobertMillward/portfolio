//
//  CompareZ0TestAid.c
//
//  Created by Robert R on 2/21/15.
//  Copyright (c) 2015 Robert Russell Millward.
//  All rights reserved.
//
#include <string.h>
#include <libc.h>
#include "CompareZ0TestAid.h"
#include "TestAidZ0.h"

static compareResultArcT
sortTwoFieldsZ0Q(thisValT thisVal,
                 thatValT thatVal,
                 dataTypeArcT onType,
                 sortNullsArcT hiLo,
                 lineNbrT lineNbr)
{
    compareResultArcT status = CompareZ0ACapi.sortTwoFields(thisVal, thatVal, onType, hiLo);
    
    return status;
}


static rankCprT
isSimilarZ0Q(thisValT thisVal, char *similarItem, dataTypeArcT tp, lineNbrT lineNbr)
{
    rankCprT rank = CompareZ0ACapi.isSimilar(thisVal, similarItem, tp);
    
    return rank;
}


static compareResultArcT
isLikeZ0Q(thisValT thisVal,
          thatValT thatVal,
          dataTypeArcT onType,
          lineNbrT lineNbr)
{
    compareResultArcT retStr = CompareZ0ACapi.isLike(thisVal, thatVal, onType);
    

    return retStr;
}


/**
 * Test tools.
 */
static Zint
sortTwoTestsZ0Q(SortTwoZ0QCdataPT items, itemCountT itemCount, dataTypeArcT dataType, sortNullsArcT nullsTo, lineNbrT driverLineNbr, lineNbrT lineNbr)
{
    Zint retVal = 0;
    
    for(int itemIx = 0 ; itemIx < itemCount ; itemIx++)
    {
        items[itemIx].recieved = sortTwoFieldsZ0Q(items[0].thisP, items[itemIx].thisP, dataType, nullsTo, lineNbr);
        
        char* okElse = "ok";
        if(items[itemIx].recieved != items[itemIx].expect )
        {
            okElse = "bad";
            retVal++;
            if(retVal == 1){
                TestAidZ0QCapi.putTestChars(items[itemIx].recieved, items[itemIx].expect, lineNbr);
            }
        }
        
        printf("****** %4d.%d twoVal %10s %10s %c %-18s %-18s %3s\n",
               lineNbr, itemIx,
               items[0].thisP, items[itemIx].thisP, dataType, items[itemIx].expect, items[itemIx].recieved, okElse);
    }
    if(retVal > 0)
    {
        printf("****** %4d.* Please see line %d in test driver\n", lineNbr, driverLineNbr);
    }
    
    return retVal;
}

static Zint // The number of failed tests
isSimilarTestsZ0Q(SimilarZ0QCdataT items[], itemCountT itemCount, dataTypeArcT dataType, lineNbrT driverLineNbr, lineNbrT lineNbr)
{
    Zint retVal = 0;
    
    for(int itemIx = 0 ; itemIx < itemCount ; itemIx++)
    {
        items[itemIx].recievedRank = isSimilarZ0Q(items[0].this, items[itemIx].this, dataType, lineNbr);
        
        char* okElse = "ok";
        if(items[itemIx].recievedRank != items[itemIx].expectRank )
        {
            okElse = "bad";
            retVal++;
            if(retVal == 1){
                TestAidZ0QCapi.putTestInts(items[itemIx].recievedRank, items[itemIx].expectRank, lineNbr);
            }
        }
        
        printf("****** %4d.%d similar %10s %10s %c %3d %3d %3s\n",
               lineNbr, itemIx,
               items[0].this, items[itemIx].this, dataType, items[itemIx].expectRank, items[itemIx].recievedRank, okElse);
    }
    if(retVal > 0)
    {
        printf("****** %4d.* Please see line %d in test driver\n", lineNbr, driverLineNbr);
    }
    
    return retVal;
}


static Zint
isLikeTestsZ0Q(LikeZ0QCdataPT items, dataTypeArcT dataType, itemCountT itemCount, lineNbrT driverLineNbr, lineNbrT lineNbr)
{
    Zint retVal = -1;
    for(int itemIx = 0 ; itemIx < itemCount ; itemIx++)
    {
        items[itemIx].recieved = isLikeZ0Q(items[0].thisP, items[itemIx].thisP, dataType, lineNbr);
        
        char* okElse = "ok";
        if(items[itemIx].recieved != items[itemIx].expect )
        {
            okElse = "bad";
            retVal++;if(retVal == 1){
                TestAidZ0QCapi.putTestChars(items[itemIx].recieved, items[itemIx].expect, lineNbr);
            }
        }
        
        printf("****** %4d.%d %s %10s %c %-16s %-16s %3s\n", // this is a like line
               lineNbr, itemIx,
               items[0].thisP, items[itemIx].thisP, dataType, items[itemIx].expect, items[itemIx].recieved, okElse);
    }
    if(retVal > 0)
    {
        printf("****** %4d.* Please see line %d in test driver\n", lineNbr, driverLineNbr);
    }
    return retVal;
}


/**
 * Specific tests of similar.
 */
static Zint // The number of failed tests
edwardSimilarTest(lineNbrT driverLineNbr)
{
    SimilarZ0QCdataT edward = {"Edward",    15};
    SimilarZ0QCdataT ed     = {"Ed",        11};
    SimilarZ0QCdataT edwd   = {"Edwd",      13};
    
    SimilarZ0QCdataT items[] =
    {
        edward,
        ed,
        edwd
    };
    
    Zint retVal = isSimilarTestsZ0Q(items, 3, CPR_FTYPE_STRL, driverLineNbr, __LINE__);
    
    return retVal;
}

/**
 * Specific tests of like.
 */
static Zint
aLikeTest(lineNbrT driverLineNbr)
{
    LikeZ0QCdataT leftItem  = {"a val", IS_LIKE_ARC, 0};
    LikeZ0QCdataT beginsW   = {"a*",    IS_LIKE_ARC, 0};
    LikeZ0QCdataT endsWith  = {"*l",    IS_LIKE_ARC, 0};
    LikeZ0QCdataT contains  = {"v",     IS_LIKE_ARC, 0};
    LikeZ0QCdataT nope      = {"x",     NOT_LIKE_ARC, 0};
    
    LikeZ0QCdataT items[] =
    {
        leftItem,
        beginsW,
        endsWith,
        contains,
        nope
    };
    
    Zint retVal = isLikeTestsZ0Q(items, CPR_FTYPE_STRL, 5, driverLineNbr, __LINE__);
    
    return retVal;
}

Zint
sortTwoTest(lineNbrT driverLineNbr)
{
    SortTwoZ0QCdataT middleStr =    {"b", IS_EQL_ARC, 0};
    SortTwoZ0QCdataT highStr =      {"a", IS_HIGH_ARC, 0};
    SortTwoZ0QCdataT lowStr =       {"c", IS_LOW_ARC, 0};
    
    SortTwoZ0QCdataT items[] =
    {
        middleStr,
        highStr,
        lowStr
    };
    
    Zint retNbr =
    sortTwoTestsZ0Q(items, 3, CPR_FTYPE_STRL, NULLS_HI_ARC, driverLineNbr, __LINE__);

    return retNbr;
}

Zint
sortNullTest(lineNbrT driverLineNbr)
{
    Zint retNbr = 0;
    
    SortTwoZ0QCdataT val = {"a", UNDEFINED_ARC, 0};
    SortTwoZ0QCdataT zip = {0,   UNDEFINED_ARC, 0};
    
    {
        SortTwoZ0QCdataT itemsZipVal[] =
        {
            zip,
            val
        };
        
        itemsZipVal[0].expect = UNDEFINED_ARC;
        itemsZipVal[1].expect = NULL_HI_ARC;
        retNbr += sortTwoTestsZ0Q(itemsZipVal, 2, CPR_FTYPE_STRL, NULLS_HI_ARC, driverLineNbr, __LINE__);
        
        itemsZipVal[1].expect = NULL_LO_ARC;
        retNbr += sortTwoTestsZ0Q(itemsZipVal, 2, CPR_FTYPE_STRL, NULLS_LO_ARC, driverLineNbr, __LINE__);
    }
    
    {
        SortTwoZ0QCdataT itemsZipVal[] =
        {
            val,
            zip
        };

        itemsZipVal[0].expect = IS_EQL_ARC;
        itemsZipVal[1].expect = NULL_LO_ARC;
        retNbr += sortTwoTestsZ0Q(itemsZipVal, 2, CPR_FTYPE_STRL, NULLS_HI_ARC, driverLineNbr, __LINE__);
        itemsZipVal[1].expect = NULL_HI_ARC;
        retNbr += sortTwoTestsZ0Q(itemsZipVal, 2, CPR_FTYPE_STRL, NULLS_LO_ARC, driverLineNbr, __LINE__);
    }
    

    return retNbr;
}

/**
 * The api interface
 */
const CompareZ0QCapiT CompareZ0QCapi =
{
    sortTwoFieldsZ0Q,
    isSimilarZ0Q,
    isLikeZ0Q,
    sortTwoTestsZ0Q,
    isSimilarTestsZ0Q,
    isLikeTestsZ0Q,
    
    edwardSimilarTest,
    aLikeTest,
    sortTwoTest,
    sortNullTest
};




//END CompareZ0TestAid.c
