#include "global_includes.h"

int os_sem_init(os_sem_t *sem, int count){
    if(sem == NULL){
        return OS_RET_NULL_PTR;
    }

    int ret = sem_init(&sem->sem, 0, count);
    return posix_os_ret_error_conv(ret);
}

int os_sem_entry(os_sem_t *sem, uint32_t timeout_ms){
    if(sem == NULL){
        return OS_RET_NULL_PTR;
    }

    struct timespec ts;
    ts.tv_sec = timeout_ms / 1000;
    ts.tv_nsec = (timeout_ms % 1000) * 1000000;

    int ret = sem_timedwait(&sem->sem, &ts);

    return posix_os_ret_error_conv(ret);
}

int os_sem_entry_wait_indefinite(os_sem_t *sem){
    if(sem == NULL){
        return OS_RET_NULL_PTR;
    }

    int ret = sem_wait(&sem->sem);

    return posix_os_ret_error_conv(ret);
}

int os_sem_entry_try(os_sem_t *sem){
    if(sem == NULL){
        return OS_RET_NULL_PTR;
    }

    return posix_os_ret_error_conv(sem_trywait(&sem->sem));
}

int os_sem_count(os_sem_t *sem){
    if(sem == NULL){
        return OS_RET_NULL_PTR;
    }
    int n;
    if(sem_getvalue(&sem->sem, &n) < 0){
        return OS_RET_INT_ERR;
    }

    return n;
}
