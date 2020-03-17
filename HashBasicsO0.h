//
//  HashBasicsO0.h
//
//  Created by Robert R on 2/3/15.
//  Copyright (c) 2020 Robert Russell Millward.  All rights reserved.
//
#ifndef HashBasicsO0_h
#define HashBasicsO0_h
// os
// helper and service api's
// data plans
#include "HashBasicsZ0Plan.h"
// api's

typedef struct HashBasicsO0HelperClassApiStruct
{
    /**
     * Will not parse past '\0' or your row-separator(s).
     */
    eightHashT (*getBasicHash)(HashBasicsZ0CtlPT ctlP);
    
    /**
     * Mod the eightHashT by hashMod.
     */
    fourHashT (*getWordHash)(char *strP);
    
    /**
     * Create a hash which falls into the 90^2 (thus 8100) category
     * with an item name as input. It doesnt actually reach
     * 90^2 so the actual limit is noted by MAX_8100_HB.
     * Non alpha-numeric and underscore are ignored.
     */
    Ssht (*get8100HashForItemName)(char *strP);
    
    /**
     * Using get8100HashForItemName(), create a hash
     * which falls into the 90^2 category
     * with a name that might start with get, set, is, etc
     * then call get8100HashForItemName().
     */
    Ssht (*get8100HashForOtherName)(char *strP);
    /**
     * Convert the hash to 8100.
     */
    void (*get8100code)(char* the8100store, Ssht hash);
    
    /**
     * The following functions give acces to an array of Union Heap TBD items
     * for the life of the thread.
     *
     * Clear my thread safe 8100
     */
    void (*clearMy8100)(uhxSubTypeT, gpSllgChar64PT);
    
    /**
     * Add my item to my thread safe 8100.
     * Return the 8100 index.
     * The hash uses get8100HashForOtherName() to support compiles.
     */
    Ssht (*addTo8100)(uhxElT, gpSllgChar64PT);
    
    /**
     * Get a pointer to my item using (returned) index.
     * Actually the pointer for any of the 8100 items can be gotten
     * meaning data can be stored.
     */
    uhxElPT (*getViaHash8100)(Ssht, gpSllgChar64PT);
    
    /**
     * Get a pointer to my item sequentially.
     */
    uhxElPT (*getSequentially8100)(gpSllgChar64PT);
    
    /**
     * Get the hash code for the most recent sequential access.
     */
    void    (*getHashCode8100)(char* here, gpSllgChar64PT);
    
}HashBasicsO0HCapiT, *HashBasicsO0HCapiPT;

#define HashBasicsHCapiT HashBasicsO0HCapiT
#define HashBasicsHCapi HashBasicsO0HCapi
extern HashBasicsHCapiT HashBasicsHCapi;


#endif /* HashBasicsO0_h */
/**
 *
 */
