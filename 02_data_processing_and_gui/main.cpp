#include <iostream>
//#include <linux/i2c-dev.h>
#include "cpp_threads.h"

using namespace std;

int main(){
    CppThreads getData;
    CppThreads processData;

    getData.Run();
    processData.Run();

    return 0;
}
