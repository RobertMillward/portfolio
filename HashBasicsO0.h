//
//  HashBasicsO0.h
//
//  Created by Robert R on 2/3/15.
//  Copyright (c) 2015 Robert Russell Millward.  All rights reserved.
//
#ifndef HashBasicsO0_h
#define HashBasicsO0_h
// os
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
     * The underscore character is ignored.
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
    
}HashBasicsO0HCapiT, *HashBasicsO0HCapiPT;

#define HashBasicsHCapiT HashBasicsO0HCapiT
#define HashBasicsHCapi HashBasicsO0HCapi
extern HashBasicsHCapiT HashBasicsHCapi;


#endif /* defined(HashBasicsO0_h) */
