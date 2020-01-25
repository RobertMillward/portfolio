//
//  TwoWayZ0.c
//
//  Created by Robert R on 3/27/2019.
//  Copyright (c) 2019 Robert Russell Millward.
//  All rights reserved.
//

#include <string.h>
//#include <stdio.h>
#include "ArchitectureZ0Plan.h"
/*
 */
#pragma mark - class data
/*
 */

/*
 */
#pragma mark - Class Methods
/*
 */
// Version Level
gpVersionLevelZ0PT
TwoWayVsnLvlZ0_getOfFuncName(const char* funcName)
{
    char* mostlyThere = strchr(funcName, '_');
    if(mostlyThere)
    {
        return (gpVersionLevelZ0PT)(mostlyThere - 2);
    }
    return (gpVersionLevelZ0PT)(funcName + strlen(funcName) - 2);
}

static void
TwoWayVsnLvlZ0_clear_fx99(gpVersionLevelZ0PPT verLvlPP)
{
    *verLvlPP = 0;
}

static void
TwoWayVsnLvlZ0_setIfNot_fx99(gpVersionLevelZ0PPT verLvlPP, cfuncNameT cFuncName)
{
    if(! *verLvlPP)
    {
        *verLvlPP = TwoWayVsnLvlZ0_getOfFuncName(cFuncName);
    }
}

static void
TwoWayVsnLvlZ0_setRegardless_fx99(gpVersionLevelZ0PPT verLvlPP, cfuncNameT cFuncName)
{
    *verLvlPP = TwoWayVsnLvlZ0_getOfFuncName(cFuncName);
}

VersionLevelZ0HCapiT VersionLevelZ0HCapi =
{
    TwoWayVsnLvlZ0_clear_fx99,
    TwoWayVsnLvlZ0_setIfNot_fx99,   // First called level sets
    TwoWayVsnLvlZ0_setIfNot_fx99,   // bottom level defaults
    TwoWayVsnLvlZ0_setRegardless_fx99
};

// Status
// As per header
static void
TwoWayStatusZ0_setDoNotCare_fx99(char **twoWay)
{
    *twoWay = DONT_CARE_ARC;
}
// As per header
static void
TwoWayStatusZ0_setMustWork_fx99(char **twoWay)
{
    *twoWay = DONT_KNOW_ARC; // will count errors in addition to returning status.
}
// As per header
static void
TwoWayStatusZ0_setMustFail_fx99(char **twoWay)
{
    *twoWay = DONT_WANT_ARC; // will not count errors in addition to returning status.
}
// As per header
static void
TwoWayStatusZ0_setMayWork_fx99(char **twoWay)
{
    *twoWay = KNOW_MAYBE_ARC; // will not count errors but will return status.
}
// As per header
static void
TwoWayStatusZ0_noteConfusion_fx99(char **twoWay)
{
    if(*twoWay != DONT_CARE_ARC)
    {
        *twoWay = KNOW_NULL_ARC;
    }
}
// As per header
static void
TwoWayStatusZ0_noteFailure_fx99(char **twoWayPP)
{
    if(*twoWayPP == DONT_KNOW_ARC)
    {
        *twoWayPP = KNOW_NO_ARC;
    }
    else if(*twoWayPP == DONT_WANT_ARC)
    {
        *twoWayPP = KNOW_YES_ARC;
    }
}
// As per header
static void
TwoWayStatusZ0_noteSuccess_fx99(char** twoWayPP)
{
    if(*twoWayPP == DONT_WANT_ARC)
    {
        *twoWayPP = KNOW_NO_ARC;
    }
    else if(*twoWayPP == DONT_KNOW_ARC)
    {
        *twoWayPP = KNOW_YES_ARC;
    }
}

TwoWayZ0HCapiT TwoWayZ0HCapi =
{
    TwoWayStatusZ0_setDoNotCare_fx99,
    TwoWayStatusZ0_setMustWork_fx99,
    TwoWayStatusZ0_setMustFail_fx99,
    TwoWayStatusZ0_setMayWork_fx99,
    TwoWayStatusZ0_noteConfusion_fx99,
    TwoWayStatusZ0_noteFailure_fx99,
    TwoWayStatusZ0_noteSuccess_fx99
};


// END TwoWayZ0.c
