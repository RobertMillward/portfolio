//
//  UserKeyboard0.h
//
//  Created by Robert R on 2/23/15.
//  Copyright (c) 2015 Robert Russell Millward.
//  All rights reserved.
//
/**
 * Keyboard/Input functions and some conversions.
 */
#ifndef __UserKeyboardO0__
#define __UserKeyboardO0__

#include <stdio.h>
#include "ArchitectureO0.h"



#define KBD_BS_STR "\b"
#define KBD_ESC_STR "\033"


typedef long menuChoiceT;

typedef struct UserKeyboardO0Y
{
    /**
     * Convert C-str to long/float/double.
     */
    Slng (*bufToLong)(
        char *inBuf);
    F1pr (*bufToFloat)(
        char *inBuf);
    F2pr (*bufToDouble)(
        char *inBuf);
    /**
     * Get a C-string from the keyboard.
     * If it is thisBig then make it 0-bytes.
     */
    void (*keyboardIn)(
        char *here,
        massOfT thisBig);
    /**
     * Get a menu choice from the keyboard.
     */
    menuChoiceT (*getMenuItem)(
        char *menuLines[],
        massOfT menuMass);
    /**
     * Get a real number from the keyboard.
     */
    Slng (*getLong)(void);
    F1pr (*getFloat)(void);
    F2pr (*getDouble)(void);
}UserKeyboardO0X, *UserKeyboardO0XP;

extern const UserKeyboardO0X UserKeyboardO0C;
#define UserKeyboardC UserKeyboardO0C

#endif /* defined(__UserKeyboardO0__) */
