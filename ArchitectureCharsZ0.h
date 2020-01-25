//
//  ArchitectureCharsZ0.h
//
//  Created by Robert R on 10/17/14.
//  Copyright (c) 2014 Robert Russell Millward.
//  All rights reserved.
//

#ifndef ArchitectureCharsZ0_h
#define ArchitectureCharsZ0_h

// Field separator as a string
#define FSS_ARC "\034"

enum extendTextE
{
    NULL_ARC,
    SOH_ARC,
    STX_ARC,
    ETX_ARC,
    EOT_ARC,
    ENQ_ARC,
    GRN_ARC,
    BEL_ARC, // 07
    BS_ARC,
    HT_ARC,
    NL_ARC,
    VT_ARC,
    NP_ARC,
    CR_ARC,
    SO_ARC,
    SI_ARC,
    DLE_ARC,
    DC1_ARC,
    DC2_ARC,
    DC3_ARC,
    DC4_ARC,
    RED_ARC,
    SYN_ARC,
    ETB_ARC,
    CAN_ARC,
    EM_ARC,
    SUB_ARC,
    ESC_ARC,
    FS_ARC,  // Field separator
    GS_ARC,
    RS_ARC,
    US_ARC,
    SP_ARC,
    NOT_ARC,
    DQUOT_ARC,
    HASH_ARC, // #
    DLLR_ARC, // $
    PCT_ARC,
    AND_ARC,
    SQUOT_ARC,
    LPARN_ARC,
    RPARN_ARC,
    AST_ARC, // *
    PLUS_ARC,
    CMMA_ARC,
    DASH_ARC,
    DOT_ARC,
    FWDSLSH_ARC, // /
    ZERO_ARC,
    ONE_ARC,
    TWO_ARC,
    THREE_ARC,
    FOUR_ARC,
    FIVE_ARC,
    SIX_ARC,
    SEVEN_ARC,
    EIGHT_ARC,
    NINE_ARC,
    COLON_ARC = 0x3A,
    SEMI_ARC,
    LT_ARC,
    EQ_ARC,
    GT_ARC,
    QUEST_ARC,
    AT_ARC,
    A_ARC,
    B_ARC,
    C_ARC,
    D_ARC,
    E_ARC,
    F_ARC,
    G_ARC,
    H_ARC,
    I_ARC,
    J_ARC,
    K_ARC,
    L_ARC,
    M_ARC,
    N_ARC,
    O_ARC,
    LBRAK_ARC = 0x5b,
    BKSLSH_ARC, // can't show the actual character
    RBRAK_ARC,
    XOR_ARC,
    UNDSCR_ARC,
    BACKQT_ARC,
    a_ARC,
    LBRCE_ARC = 0x7b,
    OR_ARC,     // pipe or |
    RBRCE_ARC,
    TILDE_ARC,
    DEL_ARC
};
#define VISIBLE_ARC NOT_ARC // The first printable visible character
#define CHARS_IN_ABET   26
#define CHARS_IN_NBRSET 10


/**
 * For encoding binary to bigger than decimal
 * Add VISIBLE_ARC to get all printable characters.
 */
#define ENCODE_BIG_ARC 92 // note: this is not ENCODE_13b_ARC

#endif // ArchitectureCharsZ0.h
