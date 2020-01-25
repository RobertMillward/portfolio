//
//  ArchitectureTransZ0.h
//
//  Created by Robert R on 10/17/19.
//  Copyright (c) 2014 Robert Russell Millward.
//  All rights reserved.
//

#ifndef ArchitectureTransZ0_h
#define ArchitectureTransZ0_h
/**
 * For code that wants the data type.
 */
typedef Ulng tranIxT;
typedef Ulng tranSerNbrT;

/**
 * The thread manager when used needs a transaction of its own.
 */
#define TRANIX_FOR_THREADER_TXL 0
#define LOG_BUF_Z0CT_TXL 8
#define LOG_BUF_Z3CT_TXL 32
#define LOG_BUF_Z8CT_TXL 1024

/**
 * The various application enviroments
 * are a basic characteristic of this library.
 */
#define DEV_JNL     "dev"
#define TEST_JNL    "test"
#define TRAIN_JNL   "train"
#define PROD_JNL    "prod"
typedef char* devOrProdT; // Actually, any one of the above four.
typedef char** devOrProdPT;

#endif // defined(ArchitectureTransZ0_h)
/**
 */
