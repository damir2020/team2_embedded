#include <iostream>
#include <pthread.h>
#include "cpp_threads.h"

using namespace std;

CppThreads::CppThreads(){
    static int num = 0;
    int id = ++num;
}


// void CppThreads::Create(){
//     if (pthread_create(&id, 0, &CppThread::Exec, this) != 0){
//         throw "Cannot create thread";
//     }
// }


// static void* CppThreads::Exec(void* thr) {
//     reinterpret_cast<CppThread *> (thr)->Run();
//     return 0;
// }

// void CppThreads::Join(){
//     pthread_join(id, NULL);
// }

void CppThreads::Run(){
 if (id == 0){
     cout << "hello" << endl;
 } else if (id == 1){
     cout << "goodbye" << endl;
 }
}
