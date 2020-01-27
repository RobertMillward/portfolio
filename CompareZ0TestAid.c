//
//  CompareZ0TestAid.c
//
//  Created by Robert R on 2/21/15.
//  Copyright (c) 2020 Robert Russell Millward.  All rights reserved.
//
// os
#include <string.h>
#include <stdio.h>
// data plan
// api's
// aids
#include "CompareZ0TestAid.h"
#include "TestAidZ0.h"

static compareResultArcT
CompareZ0TestAid_sortTwoFieldsQ(thisValT thisVal,
                 thatValT thatVal,
                 dataTypeT onType,
                 sortNullsArcT hiLo,
                 lineNbrT lineNbr)
{
    compareResultArcT status = CompareO0HCapi.sortTwoFields(thisVal, thatVal, onType, hiLo);
    
    return status;
}


static rankCprT
CompareZ0TestAid_isSimilarQ(thisValT thisVal, char *similarItem, dataTypeT tp, lineNbrT lineNbr)
{
    rankCprT rank = CompareO0HCapi.isSimilar(thisVal, similarItem, tp);
    
    return rank;
}


static compareResultArcT
CompareZ0TestAid_isLikeQ(thisValT thisVal,
          thatValT thatVal,
          dataTypeT onType,
          lineNbrT lineNbr)
{
    compareResultArcT retStr = CompareO0HCapi.isLike(thisVal, thatVal, onType);
    

    return retStr;
}


/**
 * Test tools.
 */
static Zint
CompareZ0TestAid_sortTwoTestsQ(SortTwoZ0QCdataPT items, itemCountT itemCount, dataTypeT dataType, sortNullsArcT nullsTo, lineNbrT driverLineNbr, lineNbrT lineNbr)
{
    Zint retVal = 0;
    
    for(int itemIx = 0 ; itemIx < itemCount ; itemIx++)
    {
        items[itemIx].recieved = CompareZ0TestAid_sortTwoFieldsQ(items[0].thisP, items[itemIx].thisP, dataType, nullsTo, lineNbr);
        
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
CompareZ0TestAid_isSimilarTestsQ(SimilarZ0QCdataT items[], itemCountT itemCount, dataTypeT dataType, lineNbrT driverLineNbr, lineNbrT lineNbr)
{
    Zint retVal = 0;
    
    for(int itemIx = 0 ; itemIx < itemCount ; itemIx++)
    {
        items[itemIx].recievedRank = CompareZ0TestAid_isSimilarQ(items[0].this, items[itemIx].this, dataType, lineNbr);
        
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
CompareZ0TestAid_isLikeTestsQ(LikeZ0QCdataPT items, dataTypeT dataType, itemCountT itemCount, lineNbrT driverLineNbr, lineNbrT lineNbr)
{
    Zint retVal = 0;
    for(int itemIx = 0 ; itemIx < itemCount ; itemIx++)
    {
        items[itemIx].recieved = CompareZ0TestAid_isLikeQ(items[0].thisP, items[itemIx].thisP, dataType, lineNbr);
        
        char* okElse = "ok";
        if(items[itemIx].recieved != items[itemIx].expect )
        {
            okElse = "bad";
            retVal++;
            if(retVal == 1){ // report first issue only
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
CompareZ0TestAid_edwardSimilarTest(lineNbrT driverLineNbr)
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
    
    Zint retVal = CompareZ0TestAid_isSimilarTestsQ(items, 3, CPR_FTYPE_STRL, driverLineNbr, __LINE__);
    
    return retVal;
}

/**
 * Specific tests of like.
 */
static itemCountT
CompareZ0TestAid_aLikeTest(lineNbrT driverLineNbr)
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
    
    itemCountT retVal = CompareZ0TestAid_isLikeTestsQ(items, CPR_FTYPE_STRL, 5, driverLineNbr, __LINE__);
    
    return retVal;
}

Zint
CompareZ0TestAid_sortTwoTest(lineNbrT driverLineNbr)
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
    CompareZ0TestAid_sortTwoTestsQ(items, 3, CPR_FTYPE_STRL, NULLS_HI_ARC, driverLineNbr, __LINE__);

    return retNbr;
}

Zint
CompareZ0TestAid_sortNullTest(lineNbrT driverLineNbr)
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
        retNbr += CompareZ0TestAid_sortTwoTestsQ(itemsZipVal, 2, CPR_FTYPE_STRL, NULLS_HI_ARC, driverLineNbr, __LINE__);
        
        itemsZipVal[1].expect = NULL_LO_ARC;
        retNbr += CompareZ0TestAid_sortTwoTestsQ(itemsZipVal, 2, CPR_FTYPE_STRL, NULLS_LO_ARC, driverLineNbr, __LINE__);
    }
    
    {
        SortTwoZ0QCdataT itemsZipVal[] =
        {
            val,
            zip
        };

        itemsZipVal[0].expect = IS_EQL_ARC;
        itemsZipVal[1].expect = NULL_LO_ARC;
        retNbr += CompareZ0TestAid_sortTwoTestsQ(itemsZipVal, 2, CPR_FTYPE_STRL, NULLS_HI_ARC, driverLineNbr, __LINE__);
        itemsZipVal[1].expect = NULL_HI_ARC;
        retNbr += CompareZ0TestAid_sortTwoTestsQ(itemsZipVal, 2, CPR_FTYPE_STRL, NULLS_LO_ARC, driverLineNbr, __LINE__);
    }
    

    return retNbr;
}

/**
 * The api interface
 */
const CompareZ0QCapiT CompareZ0QCapi =
{
    CompareZ0TestAid_sortTwoFieldsQ,
    CompareZ0TestAid_isSimilarQ,
    CompareZ0TestAid_isLikeQ,
    CompareZ0TestAid_sortTwoTestsQ,
    CompareZ0TestAid_isSimilarTestsQ,
    CompareZ0TestAid_isLikeTestsQ,
    
    CompareZ0TestAid_edwardSimilarTest,
    CompareZ0TestAid_aLikeTest,
    CompareZ0TestAid_sortTwoTest,
    CompareZ0TestAid_sortNullTest
};

//END CompareZ0TestAid.c
/**
 *
 */
