#ifndef _CSAL_STRUCT_DEFINITIONS_H
#define _CSAL_STRUCT_DEFINITIONS_H

#include "pthread.h"
#include "semaphore.h"
#include "stdint.h"
#include "stdbool.h"
#include "semaphore.h"

typedef struct os_setbits_t{
    //OSSignal signal;
    volatile int bits;
    sem_t bit_sem;
    volatile bool sem_wait;
}os_setbits_t;

typedef struct os_mut_t{
    pthread_mutex_t mutex;    
}os_mut_t;

typedef struct os_sem_t{
    sem_t sem;
}os_sem_t;

typedef struct os_thread_id_s{
    
}os_thread_id_s;
#endif