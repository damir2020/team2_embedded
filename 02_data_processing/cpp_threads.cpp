#include <iostream>
#include <pthread.h>
#include "cpp_threads.h"

using namespace std;

int CppThreads::num = 0;

CppThreads::CppThreads(){
    id = num++;
}

void CppThreads::Create(){
    pthread_create(&id, 0, &CppThreads::Exec, this);
}

void* CppThreads::Exec(void* arg){
    ((CppThreads*)arg)->CppThreads::Run();
    return 0;
}

// void CppThreads::Join(){
//     pthread_join(id, NULL);
// }

void CppThreads::Run(){
    if (id == 0){
        cout << "Getting Data" << endl;
    } else if (id == 1){
        cout << "Processing Data" << endl;
    } else if (id == 2){
        cout << "Broadcasting Data" << endl;
    } else if (id == 3){
        cout << "Updating GUI" << endl;
    }
}
