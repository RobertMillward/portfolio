//
//  DictO3.h
//  2020Apr21Dev
//
//  Created by Robert Russell Millward on 2/20/20.
//  Copyright © 2020 Robert Russell Millward. All rights reserved.
//
#ifndef DictO3_h
#define DictO3_h
// os
// helper and service api's
// data plans
#include "DictZ3Plan.h"

/**
 * Api to the global universal-column-id (uci) and thesarus-to-values (tav) library.
 */
typedef struct DictionaryTavO3ServiceClassApiStruct
{
    /**
     * Process the column headers to assign csv (as the name defaults to) columns to the global thesarus.
     * gp64P->threadIx must be set.
     */
    csvColDataPT        (*newHdrsToFields)(csvColHeadersPT, gpSllgChar64PT);
    /**
     *
     * gp64P->threadIx must be set.
     */
    csvColDataPT        (*newDataToFields)(csvColDataPT, gpSllgChar64PT);
    /**
     *
     * gp64P...threadIx must be set.
     * must be run after newDataToFields
     */
    void                (*putSubXYZtoFields)(subCatPT, indeXT, whYT, whoZT, gpSllgChar64PT);
    /**
     * Get the pointer to data for a UCI for your thread.
     * gp64P...threadIx must be set.
     */
    ValPtrASizeZ3dataT  (*getFieldViaUci)(UniversalColumnIdT, gpSllgChar64PT);
    /**
     * Create row at this target for these universal columns in this UCI_CATEGORY terminated array.
     * All Uci must be from the same category.
     * Except for the category, meta felds what, whY, whoZ, and indeX must be requested.
     * The category/sub (What identifier) is the first output which can be skipped if desired.
     * gp64P...threadIx must be set. 
     */
    void            (*createRow)(targetPT, massOfT, UniversalColumnIdT[], gpSllgChar64PT);
    
}DictTavO3SCapiT, *DictTavO3SCapiPT;
extern DictTavO3SCapiT DictTavO3SCapi;


/**
 * Services over and above stock store-and-forward.
 */
typedef struct DictTavExtras03ServiceClassApiStruct
{
    /**
     * latitude and longitude arguments in decimal strings as "-47.228" or "57.914".
     */
    void    (*getLongLat)(longLatPT, gpSllgChar64PT);
    /**
     * the distance between two points given in
     */
    double  (*distance) (longLatPT place, longLatPT dest);
    
}DictTavExtrasO3SCapiT;
extern DictTavExtrasO3SCapiT DictTavExtrasO3SCapi;


/**
 * These hold the isPresent bits corresponding to the UniversalColumnIdT.
 * The bits are accessed via bitHolders[(UniversalColumnIdT - 1)/ 32] & (1 <<  (UniversalColumnIdT % 32).
 */
#define TAV_BITS_PER 32
typedef struct DictionaryBitsThisStruct
{
    void (*set)  (struct DictionaryBitsThisStruct*, UniversalColumnIdT);
    bool (*isSet)(struct DictionaryBitsThisStruct*, UniversalColumnIdT);
    bool (*clear)(struct DictionaryBitsThisStruct*);

}DictBitsZ3SIthisT, *DictBitsZ3SIthisPT;


#endif /* DictO3_h */
/**
 *
 */
