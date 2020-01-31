//
//  CityY0.c
//
//  Created by Robert R on 10/08/20.
//  Copyright (c) 2020 Robert Russell Millward.  All rights reserved.
//
// os
#include <string.h>
#include <ctype.h>
// data
#include "CityY0Plan.h"
// api's
#include "CityT0.h"

static char *nameParts[] =
{
    "tac", "oma", "se", "attle", "pas", "co", "waits", "lewis", "clarks", "ritz", "oro", "fino", "kam", "iah", "center"
};

static char*
nameEndings[] =
{
    "vill", "ton"
};

static void
CityT0_name_fx99(DataAidLocY0HClocPT locP, gpSllgChar64PT outP)
{
    locP->seedAfterCity = 0;
    locP->seedAfterCity = locP->seedAfterCity + ((locP->x.cityX  + 1) * 11) * 13;
    locP->seedAfterCity = locP->seedAfterCity + ((locP->y.cityY  + 1) * 11) * 13;
    locP->seedAfterCity = locP->seedAfterCity + ((locP->x.stateX + 1) * 11) * 13;
    locP->seedAfterCity = locP->seedAfterCity + ((locP->y.stateY + 1) * 11) * 13;
    
    int modOf = sizeof(nameParts) / sizeof(nameParts[0]);
    
    strcpy(outP->theCharValue, "");
    strcat(outP->theCharValue, nameParts[locP->seedAfterCity % modOf]);
    strcat(outP->theCharValue, nameParts[(locP->seedAfterCity + 91) % modOf]);
    
    if((locP->seedAfterCity % modOf) == 0){
        // note: modOf changes
        modOf = sizeof(nameEndings) / sizeof(nameEndings[0]);
        strcat(outP->theCharValue, nameEndings[locP->seedAfterCity % modOf]);
    }
    
    outP->theCharValue[0] = toupper(outP->theCharValue[0]);
}

CityT0HCapiT CityT0HCapi =
{
    CityT0_name_fx99
};


/**
 */
