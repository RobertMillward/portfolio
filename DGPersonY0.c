//
//  DGPersonY0.c
//
//  Created by Robert R on 10/08/20.
//  Copyright (c) 2020 Robert Russell Millward.  All rights reserved.
//
// os
#include <string.h>
#include <ctype.h>
// data plan
#include "DGPersonY0Plan.h"
// api's
#include "DGPersonT0.h"


#pragma mark - phonics and words for names
/**
 * Converts the number 0-15 to a number of phonics to be used to make a name
 */
static Uchr phonicCountRedistribution[16] = {2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 4, 5, 6, 7};


static char* phonicsPlus[] = {
    "ab", "ac", "ad", "af", "ag", "ah", "al", "am", "an", "ap", "ar", "as", "at", "av", "aw", "ax",
    "ba", "be",       "bi", "bl", "bo", "br", "bu", "by",
    "ca", "ce", "ch", "ci", "cl", "co", "cr", "cu",       "cy",
    "da", "de",       "di",       "do", "dr", "du", "dw", "dy",
    "ea", "ec", "ed", "ef", "eg", "eh", "ek", "el", "em", "en", "ep", "eq", "er", "es", "et", "ev", "ew", "ex",
    "fa", "fe", "fh", "fi", "fl", "fo", "fr", "fu",       "fy",
    "ga", "ge",       "gi",       "go", "gr", "gu", "gw", "gy",
};

//static char *specialBegin[] = {
//    "Von", "Mc"
//};

//static char *specialEnd[] = {
//    "sen", "son"
//};

#define IS_FAM 1
#define IS_PSN 2

static void
PersonT0_anyName_fx99(DataAidLocY0HClocPT locP, gpSllgChar64PT outP, int famOrGiven)
{
    strcpy(outP->theCharValue, "");
    
    Ulng multX = locP->seedAfterLot;
    
    if(famOrGiven == IS_PSN){
        switch(locP->personNumber)
        {
            case 0: multX += 27431; break;
            case 1: multX += 72431; break;
            case 2: multX += 27431; break;
            case 3: multX += 43271; break;
            case 4: multX += 31274; break;
            case 5: multX += 47431; break;
            case 6: multX += 34431; break;
            case 7: multX += 13431; break;
        }
    }
    // note: redistribution
    int maxPhonics = (multX % 16);
    maxPhonics = phonicCountRedistribution[maxPhonics];
    
    // Build name
    int doMod = sizeof(phonicsPlus) / sizeof(phonicsPlus[0]);
    for(int phIx = 0; phIx < maxPhonics; phIx++)
    {
        Ulng modIn = -1;
        
        switch(phIx)
        {
            case 0: modIn = multX + 0;              break;
            case 1: modIn = multX + locP->y.lotY;   break;
            case 2: modIn = multX + locP->x.lotX;   break;
            case 3: modIn = multX + locP->x.cityX;  break;
            case 4: modIn = multX + locP->y.cityY;  break;
            case 5: modIn = multX + locP->x.stateX; break;
            case 6: modIn = multX + locP->y.stateY; break;
            case 7: modIn = multX + locP->floor;    break;
        }
        modIn += phIx;
        strcat(outP->theCharValue, phonicsPlus[modIn % doMod]);
    }
    outP->theCharValue[0] = toupper(outP->theCharValue[0]);
}

static void
PersonT0_givenName_fx99(DataAidLocY0HClocPT locP, gpSllgChar64PT outP)
{
    PersonT0_anyName_fx99(locP, outP, IS_PSN);
}

static void
PersonT0_famName_fx99(DataAidLocY0HClocPT locP, gpSllgChar64PT outP)
{
    PersonT0_anyName_fx99(locP, outP, IS_FAM);
}

static void
PersonT0_age_fx99(DataAidLocY0HClocPT loc, gpSllgChar64PT out)
{
    strcpy(out->theCharValue, "");
    out->theLongValue = 2 * loc->personNumber;
    if(loc->personNumber < 2)
    {
        out->theLongValue += 18;
    }
    if(loc->personNumber < 1)
    {
        out->theLongValue += 3;
    }
}

static void
PersonT0_nextPerson_fx99(DataAidLocY0HClocPT locP)
{
    if(locP->x.firstTimeIn == 1){
        locP->x.firstTimeIn = 0;
        // initialize a new one
        locP->x.moreToDo = 1;
        locP->x.familySize = 7;
    }
    if(locP->x.moreToDo == 0){
        return;
    }
    
    if(locP->personNumber != 0)
    {
        // move to the next person in this same lot, city, and state
        locP->personNumber--;
    }else{
        // make assignments
        locP->personNumber = locP->x.familySize;
        
        // possibly on a new floor
        if(locP->floor > 0)
        {
            locP->floor--;
        }
        else
        {
            // move to the next lot
            if(locP->x.direction == SOUTH_DIRECTION){
                locP->y.lotY++;
                
                if(locP->y.lotY == 0){
                    // used up the lots in this column of this city
                    // so next city south
                    locP->y.cityY++;
                    
                    if(locP->y.cityY == 0)
                    {
                        locP->y.stateY++;
                        // See if there is more available after this one
                        if(locP->x.stateX == 0){
                            locP->x.moreToDo = 0;
                        }
                    }
                }
            }else{
                locP->x.lotX++;
            
                if(locP->x.lotX == 0){
                    locP->x.cityX++;
                    
                    if(locP->x.cityX == 0)
                    {
                        locP->x.stateX++;
                        
                        // See if there is more available after this one
                        if(locP->x.stateX == 0){
                            locP->x.moreToDo = 0;
                        }
                    }
                }
            }
        }
    }
    
    // After the dust from moving to the next person settles then make adjustments
    // start a new family where the size is smaller closer to the coast
    locP->x.familySize = 7;
    
    if(locP->x.stateX == 0 || locP->x.stateX == 7) {locP->x.familySize--;}
    if(locP->x.stateX <= 1 || locP->x.stateX >= 6) {locP->x.familySize--;}
}




PersonT0HCapiT PersonT0HCapi =
{
    PersonT0_famName_fx99,
    PersonT0_givenName_fx99,
    PersonT0_age_fx99,
    PersonT0_nextPerson_fx99
};
// END DGPersonY0.c
/**
 */
