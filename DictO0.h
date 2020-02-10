//
//  DictO0.h - A thread safe library to robustly support the creation of a DictZ0AnewT.
//
//  Created by Robert Russell Millward on 12/4/19.
//  Copyright (c) 2019 Robert Russell Millward. All rights reserved
//
#ifndef DictO0_h
#define DictO0_h
#include "DictZ0Plan.h"

typedef const struct DictO0SCapiS
{
    /**
     * Get the field Dictionary.
     */
    DictZ0SIdataT    (*getDict)(sourcePT, cfuncNameT, gpSllgChar64PT);
    
    /**
     * Check the source data using the field dictionary.
     * This is to assure that the data to be stored has acceptable content.
     * The Row.addMore() will impose additional accptance criteria.
     */
    void
    (*checkViaDict) (DictZ0SIdataT, gpSllgChar64PT);
    
    /**
     * Format the source data using the dictionary.
     * This is simlple formatting.
     */
    void
    (*formatViaDict)(DictZ0SIdataT, targetPT, targetLengthT, gpSllgChar64PT);
    
}DictO0SCapiT, *DictO0SCapiPT;

#define DictSCapiT DictO0SCapiT
#define DictSCapi DictO0SCapi
extern DictSCapiT DictSCapi;

#endif /* DictO0_h */
/**
 A Dictionary is an essential building block in the library.
 Several data types are supported as can be seen from CompareZ0Plan.h.
 
 FEATURED 12/11/19
 */
