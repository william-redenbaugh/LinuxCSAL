#include "os_thread.h"
#include "pthread.h"
#include "signal.h"
#include "errno.h"

os_thread_id_t os_add_thread(thread_func_t p, void * arg, int stack_size, void *stack){
    pthread_t t;
    pthread_create(&t, NULL, (void*(*)(void*))p, arg);

    return(os_thread_id_t)t;
}

os_thread_id_t os_kill_thread(os_thread_id_t target_thread_id){
    int ret = pthread_kill((pthread_t)target_thread_id, SA_SIGINFO);

    if(ret == ESRCH){
        return -1;
    }

    return target_thread_id;
}

void os_kill_self_thread(void){
    os_thread_id_t id = os_current_id();

    os_kill_thread(id);
}

uint64_t get_current_time_millis() {
    struct timespec current_time;
    clock_gettime(CLOCK_REALTIME, &current_time);
    return (uint64_t)(current_time.tv_sec * 1000 + current_time.tv_nsec / 1000000);
}