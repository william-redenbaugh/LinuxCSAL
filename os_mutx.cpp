#include "pthread.h"
#include "time.h"
#include "global_includes.h"

int os_mut_init(os_mut_t *mut){
    if(mut == NULL)
        return OS_RET_INVALID_PARAM;

    int mut_ret = pthread_mutex_init(&mut->mutex, NULL);
    return posix_os_ret_error_conv(mut_ret);
}

int os_mut_entry(os_mut_t *mut, uint32_t timeout_ms){
    if(mut == NULL)
        return OS_RET_INVALID_PARAM;

    struct timespec ts;
    ts.tv_sec = timeout_ms / 1000;
    ts.tv_nsec = (timeout_ms % 1000) * 1000000;
    int mut_ret = pthread_mutex_timedlock(&mut->mutex, &ts);

    return posix_os_ret_error_conv(mut_ret);
}

int os_mut_try_entry(os_mut_t *mut){
    return os_mut_entry(mut, 0);
}

int os_mut_count(os_mut_t *mut){
    if(mut == NULL)
        return OS_RET_INVALID_PARAM;
    
    return mut->mutex.__data.__count;
}

int os_mut_entry_wait_indefinite(os_mut_t *mut){
    if(mut == NULL)
        return OS_RET_INVALID_PARAM;

    int mut_ret = pthread_mutex_lock(&mut->mutex);

    return posix_os_ret_error_conv(mut_ret);
}

int os_mut_exit(os_mut_t *mut){
    if(mut == NULL){
        return OS_RET_INVALID_PARAM;
    }

    int mut_ret = pthread_mutex_unlock(&mut->mutex);

    return posix_os_ret_error_conv(mut_ret);
}

int os_mut_deinit(os_mut_t * mut){

    return OS_RET_OK;
}