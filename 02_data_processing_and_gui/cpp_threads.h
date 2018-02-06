#ifndef CPP_THREADS_H
#define CPP_THREADS_H

class CppThreads{
    public:
        CppThreads();
        virtual ~CppThreads(){};
        // void Create();
        // void Join();
        void Run();
    private:
        // static void* exec(void* thr);
};

#endif // CPP_THREADS_H
