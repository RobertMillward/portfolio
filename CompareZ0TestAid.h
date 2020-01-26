//
//  CompareZ0TestAid.h
//
//  Created by Robert R on 2/21/15.
//  Copyright (c) 2015 Robert Russell Millward.
//  All rights reserved.
//

#ifndef CompareZ0TestAid_h
#define CompareZ0TestAid_h

#include "CompareZ0.h"

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

typedef struct CompareZ0QualityClassApiStructure
{
    /**
     *
     */
    compareResultArcT   (*sortTwoFields)(thisValT, thatValT, dataTypeArcT, sortNullsArcT, lineNbrT);
    /**
     *
     */
    rankCprT            (*isSimilar)(thisValT, simToValT, dataTypeArcT, lineNbrT);
    /**
     *
     */
    compareResultArcT   (*isLike)(thisValT, thatValT, dataTypeArcT, lineNbrT);
    
    /**
     * Test tools
     * - returns are -1 for failure else success
     */
    Zint   (*sortTwoQ)(SortTwoZ0QCdataPT, itemCountT, dataTypeArcT, sortNullsArcT, lineNbrT dvrLinNbr, lineNbrT);
    Zint   (*isSimilarQ)(SimilarZ0QCdataT items[], itemCountT, dataTypeArcT, lineNbrT dvrLinNbr, lineNbrT);
    Zint   (*isLikeQ)(LikeZ0QCdataPT, dataTypeArcT, itemCountT, lineNbrT dvrLinNbr, lineNbrT);
    
    /**
     * Tests
     */
    Zint (*edwardSimilarTest)(lineNbrT);
    Zint (*aLikeTest)(lineNbrT);
    Zint (*sortTwoTest)(lineNbrT);
    Zint (*sortNullTest)(lineNbrT);
    
}CompareZ0QCapiT, *CompareZ0QCapiPT;


extern const CompareZ0QCapiT CompareZ0QCapi;

#endif /* defined(CompareZ0TestAid_h) */
