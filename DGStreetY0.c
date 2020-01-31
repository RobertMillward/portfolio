//
//  StreetY0.c - 
//
//  Created by Robert R on 10/08/20.
//  Copyright (c) 2020 Robert Russell Millward.  All rights reserved.
//
// os
#include <libc.h>
#include <string.h>
// data
#include "StreetY0Plan.h"
// api's
#include "StreetT0.h"


static char *streetNames[] =
{
    "Main",
    "Aspen",
    "Birch",
    "Cedar",
    "Elm",
    "Maple"
    "Pine",
    "Tamarack",
    "Teak"
};

static char *avenueNames[] =
{
    "Cool",
    "Washington",
    "Adams",
    "Jefferson",
    "Clinton",
    "Bush",
    "Obama",
    "Trump"
};

static void
StreetT0_getNumber_fx99(DataAidLocY0HClocPT locP, gpSllgChar64PT outP)
{
    int streetNbr = (locP->x.lotX / 10) + 1; // ten houses per block on two sides of street
    int houseNbr = ((locP->x.lotX % 10) + 1) * 7;
    sprintf(outP->theCharValue, "%d%02d ", streetNbr, houseNbr);
}

static void
StreetT0_getName_fx99(DataAidLocY0HClocPT locP, gpSllgChar64PT outP)
{
    locP->seedAfterStreet   = locP->seedAfterCity   + ((locP->y.lotY + 1) / 10) * 1417 + ((locP->x.lotX + 1) / 10) * 73;
    locP->seedAfterLot      = locP->seedAfterStreet + locP->y.lotY * 531 + locP->x.lotX * 91;
    
    strcpy(outP->theCharValue, "");
    // the street I live on is determined by the distance perpindicular to my travel
    if(locP->x.direction == 0){
        int aveNameIx = locP->y.lotY / 10; // ten houses per block on two sides of street
        strcat(outP->theCharValue, avenueNames[aveNameIx]);
        strcat(outP->theCharValue, " Ave");
    }else{
        int streetNameIx = locP->x.lotX / 10; // ten houses per block on two sides of street
        strcat(outP->theCharValue, streetNames[streetNameIx]);
        strcat(outP->theCharValue, " St");
    }
}

static void
StreetT0_getFloor_fx99(DataAidLocY0HClocPT locP, gpSllgChar64PT outP)
{
    strcpy(outP->theCharValue, "");
    
    
}


StreetT0HCapiT StreetT0HCapi =
{
    StreetT0_getNumber_fx99,
    StreetT0_getName_fx99,
    StreetT0_getFloor_fx99
};

/**
 */
