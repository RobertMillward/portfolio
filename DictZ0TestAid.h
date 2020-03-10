//
//  DictZ0TestAid.h
//  2020Mar10Dev
//
//  Created by Robert Russell Millward on 12/4/19.
//  Copyright (c) 2020 Robert Russell Millward. All rights reserved.
//
#ifndef DictZ0TestAid_h
#define DictZ0TestAid_h
// os
// helper api's
#include "DictO0.h"
// data plans
// app api's
// quality

/**
 * A thread safe library to support the stages of Dict creation.
 */
typedef const struct DictO0QCapiS
{
    /**
     * Tests for generating the field dictionary.
     */
    ErrorWarnCountT (*getDictTests)(dataTypeT, lineNbrT);
    /**
     * Tests for checking the source data using the field dictionary.
     */
    ErrorWarnCountT (*checkDictDTXXTests)(lineNbrT);
    /**
     * Tests for formatting the data using the field dictionary.
     */
    ErrorWarnCountT (*formatDictDUBLTests)(lineNbrT);
    ErrorWarnCountT (*formatDictDTXXTests)(lineNbrT);
    ErrorWarnCountT (*formatDictTEXTTests)(lineNbrT);
    ErrorWarnCountT (*formatDictSTRXTests)(lineNbrT);
    ErrorWarnCountT (*formatDictINTGTests)(lineNbrT);
    
}DictO0QCapiT, *DictO0QCapiPT;

extern DictO0QCapiT DictO0QCapi;

#endif /* DictZ0TestAid_h */
/**
 */
