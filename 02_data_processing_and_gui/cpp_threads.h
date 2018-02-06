#ifndef CPP_THREADS_H
#define CPP_THREADS_H

class CppThreads{
    protected:
    private:
        pthread_t id = 0;
        static void* exec(void* thr);
    public:
        CppThreads();
        virtual ~CppThreads();
        void create();
        void join();
        void run();
};

#endif // CPP_THREADS_H
