//
//  CompareZ0TestAid.h
//
//  Created by Robert R on 2/21/15.
//  Copyright (c) 2020 Robert Russell Millward.  All rights reserved.
//
#ifndef CompareZ0TestAid_h
#define CompareZ0TestAid_h
// os
// data plan
// api's
#include "CompareO0.h"

typedef struct SortTwoZ0QualityClassDataStructure
{
    thisValT thisP;
    compareResultArcT expect;
    compareResultArcT recieved;
}SortTwoZ0QCdataT, *SortTwoZ0QCdataPT;

typedef struct SimilarZ0QualityClassDataStructure
{
    thisValT this; // The extra items along with the first item are checked against the first item.
    rankCprT expectRank;
    rankCprT recievedRank;
}SimilarZ0QCdataT, *SimilarZ0QCdataPT;

typedef struct LikeZ0QualityClassDataStructure
{
    thisValT thisP;
    compareResultArcT expect;
    compareResultArcT recieved;
}LikeZ0QCdataT, *LikeZ0QCdataPT;

/**
 * The top is like CompareO0.h  with a line number included and the bottom adds the test funxtions.
 */
typedef struct CompareZ0QualityClassApiStructure
{
    /**
     * See CompareO0.h
     */
    compareResultArcT   (*sortTwoFields)(thisValT, thatValT, dataTypeT, sortNullsArcT, lineNbrT);
    /**
     * See CompareO0.h
     */
    rankCprT            (*isSimilar)(thisValT, simToValT, dataTypeT, lineNbrT);
    /**
     * See CompareO0.h
     */
    compareResultArcT   (*isLike)(thisValT, thatValT, dataTypeT, lineNbrT);
    
    /**
     * Test tools
     * - returns are -1 for failure else success
     */
    Zint   (*sortTwoQ)(SortTwoZ0QCdataPT, itemCountT, dataTypeT, sortNullsArcT, lineNbrT dvrLinNbr, lineNbrT);
    Zint   (*isSimilarQ)(SimilarZ0QCdataT items[], itemCountT, dataTypeT, lineNbrT dvrLinNbr, lineNbrT);
    Zint   (*isLikeQ)(LikeZ0QCdataPT, dataTypeT, itemCountT, lineNbrT dvrLinNbr, lineNbrT);
    
    /**
     * Tests
     */
    Zint (*edwardSimilarTest)(lineNbrT);
    itemCountT (*aLikeTest)(lineNbrT);
    Zint (*sortTwoTest)(lineNbrT);
    Zint (*sortNullTest)(lineNbrT);
    
}CompareZ0QCapiT, *CompareZ0QCapiPT;


extern const CompareZ0QCapiT CompareZ0QCapi;

#endif /* defined(CompareZ0TestAid_h) */
