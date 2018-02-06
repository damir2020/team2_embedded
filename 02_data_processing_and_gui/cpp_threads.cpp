#include <pthread.h>
#include "cpp_threads.h"

void CppThreads::CppThreads(){}

void CppThreads::Create(){
    if (pthread_create(&id, 0, &CppThread::exec, this) != 0) {
        throw "Cannot create thread";
    }
}

void CppThreads::Join(){
    pthread_join(id, NULL);
}

static void* exec(void* thr) {
    reinterpret_cast<CppThread *> (thr)->run();
    return 0;
}
