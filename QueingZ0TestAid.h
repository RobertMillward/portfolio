//
//  QueingZ0TestAid.h - Testing the communication class for queueing.
//
//  Created by Robert R on 11/13/14.
//  Copyright (c) 2020 Robert Russell Millward.  All rights reserved.
//
#ifndef QueingZ0TestAid_h
#define QueingZ0TestAid_h

// Used to populate the structure below
// - isrw:
#define QUEUED_NOTAPP "0.NotApp"
#define QUEUED_READER "1.Reader"
#define QUEUED_WRITER "2.Writer"
// - status:
// -- going in:
// --- IDH_DO_HERE_INIT
// --- IDH_DONE_ELSEWHERE
// --- *be sure and change before dequeue if
// --- *you don't want the queue destroyed.
// -- coming out:
// --- CEAOK   (it worked)
// --- CEINVAL (not initialized)

typedef struct QueingZ0QICallStruct
{
    const char *isrw;
    char *status;
    void **rwqInfo;
    const int   txIX;
}QueingZ0QICallT, *QueingZ0QICallPT;



/**
 * The quality api contains instrumented connections to the application api
 * and to predefined tests.
 */
typedef struct QueingZ0QualityClassApiStruct
{
    /**
     * Init level 0 queues.
     */
    void (*initLevel0)(gpTxPplGrpBatchTwoWayZ0PT, lineNbrT);
    
    /**
     * Connect a scenario to a level 0 queue.
     */
    void (*connect)(QueingZ0HCscenarioDataPT, gpTxPplGrpBatchTwoWayZ0PT, lineNbrT);
    
    /**
     * Enque using a provided good scenario.
     */
    void (*doDoEnqueueReader)(QueingZ0HCscenarioDataPT, gpTxPplGrpBatchTwoWayZ0PT, lineNbrT);
    void (*doDoEnqueueWriter)(QueingZ0HCscenarioDataPT, gpTxPplGrpBatchTwoWayZ0PT, lineNbrT);
    
    /**
     * Deque using the same scenario.
     */
    void (*doDoDequeueReader)(QueingZ0HCscenarioDataPT, gpTxPplGrpBatchTwoWayZ0PT,lineNbrT);
    void (*doDoDequeueWriter)(QueingZ0HCscenarioDataPT, gpTxPplGrpBatchTwoWayZ0PT,lineNbrT);
    
    // Predefined tests
    /**
     * Safety and robustness tests
     */
    ErrorWarnCountT (*safetyQ)(lineNbrT);
    
    /**
     * General use tests
     */
    ErrorWarnCountT (*generalQ)(lineNbrT);
    
    /**
     * Misuse tests
     */
    ErrorWarnCountT (*misuseQ)(lineNbrT);
    
    /**
     * Stress tests
     */
    ErrorWarnCountT (*stressThreadingQ)(lineNbrT);
    ErrorWarnCountT (*stressQueingQ)(lineNbrT);
    
}QueingZ0QCapiT;

extern QueingZ0QCapiT QueingZ0QCapi;

#endif /* defined(QueingZ0TestAid_h) */
/**
 * The communication class for queueing.
 *
 * When queueing is not initialized then these
 * variables are all NULL. When initQueing() has
 * been called then they are all set appropriately.
 */
