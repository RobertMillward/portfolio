//
//  DictO0.h - A thread safe library to robustly support the creation of a DictZ0AnewT.
//
//  Created by Robert Russell Millward on 12/4/19.
//  Copyright (c) 2019 Robert Russell Millward. All rights reserved
//
#ifndef DictO0_h
#define DictO0_h
#include "DictZ0Plan.h"

typedef const struct DictO0ACapiS
{
    /**
     * Get the field Dictionary.
     */
    DictZ0AInewT
    (*getDict)(sourcePT, cfuncNameT, gpTxPplGrpBatchTwoWayZ0PT);
    
    /**
     * Check the source data using the field dictionary.
     * This is to assure that the data to be stored has acceptable content.
     * The Row.addMore() will impose additional accptance criteria.
     */
    void
    (*checkViaDict)(DictZ0AInewT, gpTxPplGrpBatchTwoWayZ0PT);
    
    /**
     * Format the source data using the dictionary.
     * This is simlple formatting.
     */
    void
    (*formatViaDict)(DictZ0AInewT, targetPT, targetLengthT, gpTxPplGrpBatchTwoWayZ0PT);
    
}DictO0ACapiT, *DictO0ACapiPT;

#define DictACapiT DictO0ACapiT
#define DictACapi DictO0ACapi
extern DictACapiT DictACapi;

#endif /* defined(DictO0_h) */
/**
 A Dictionary is an essential building block in the library.
 Several data types are supported as can be seen from CompareZ0Plan.h.
 
 FEATURED 12/11/19
 */
