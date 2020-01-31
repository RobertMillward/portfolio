//
//  StateY0.c - support for state level information generation
//
//  Created by Robert R on 10/08/20.
//  Copyright (c) 2020 Robert Russell Millward.  All rights reserved.
//
// os
#include "libc.h"
#include "string.h"
// data plan 
#include "StateY0Plan.h"
// api's
#include "StateT0.h"

static char *stateCode[5][8] =
{
    {"WA", "ID", "MT", "MT", "ND", "MN", "WI", "MI"},
    {"OR", "ID", "ID", "WY", "NB", "IA", "IL", "IN"},
    {"CA", "NV", "UT", "CO", "KS", "MS", "TN", "KY"},
    {"CA", "CA", "WY", "NM", "TX", "AR", "AL", "GA"}
};

static char *stateZip3[5][8] =
{
    {"993", "835", "590", "591", "0ND", "0MN", "0WI", "0MI"},
    {"454", "836", "0ID", "0WY", "0NB", "0IA", "0IL", "0IN"},
    {"930", "0NV", "0UT", "0CO", "0KS", "0MS", "0TN", "0KY"},
    {"960", "0CA", "0WY", "0NM", "0TX", "0AR", "0AL", "0GA"}
};

static Usht statePopulation[5][8] = // millions
{
    {6, 2, 8, 8, 8, 8, 8, 8},
    {4, 3, 8, 8, 8, 8, 8, 8},
    {8, 8, 8, 8, 8, 8, 8, 8},
    {8, 8, 8, 8, 8, 8, 8, 8}
};



static void
StateY0_codeOf_fx99(DataAidLocY0HClocPT locP, gpSllgChar64PT outP)
{
    strcpy(outP->theCharValue, stateCode[locP->y.stateY][locP->x.stateX]);
}

static void
StateY0_zip3Of_fx99(DataAidLocY0HClocPT locP, gpSllgChar64PT outP)
{
    // The low two.
    int myZip = locP->y.cityY + locP->x.cityX;
    sprintf(outP->theCharValue, "%s%02d", stateZip3[locP->y.stateY][locP->x.stateX], myZip);
}

static void
StateY0_popOf_fx99(DataAidLocY0HClocPT locP, gpSllgChar64PT outP)
{
    strcpy(outP->theCharValue, "");
    outP->theLongValue = statePopulation[locP->y.stateY][locP->x.stateX];
}


StateT0HCapiT StateT0HCapi =
{
    StateY0_codeOf_fx99,
    StateY0_zip3Of_fx99,
    StateY0_popOf_fx99
};


/**
 */
