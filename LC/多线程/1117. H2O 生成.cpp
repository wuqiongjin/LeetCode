//信号量
#include <semaphore.h>
class H2O {
public:
    H2O() {
        sem_init(&s1, 0, 2);    //H元素的初值是2
        sem_init(&s2, 0, 1);    //O元素的初值是1
    }

    void hydrogen(function<void()> releaseHydrogen) 
    {
        sem_wait(&s1);   
        releaseHydrogen();
        ++cnt;
        if(cnt == 2)
            sem_post(&s2);  //H累计到2的时候，就去通知O元素
    }

    void oxygen(function<void()> releaseOxygen) 
    {
        sem_wait(&s2);
        releaseOxygen();
        cnt = 0;
        sem_post(&s1);
        sem_post(&s1);
    }
private:
    sem_t s1;
    sem_t s2;
    int cnt = 0;
};


//条件变量
class H2O {
    mutex mtx;
    condition_variable cv;
    int cntH=0;
public:
    H2O() {
    }
    void hydrogen(function<void()> releaseHydrogen) {
        unique_lock<mutex>locker(mtx);
        cv.wait(locker,[&]{return cntH<2;});
        releaseHydrogen();
        cntH++;
        cv.notify_all();
    }
    void oxygen(function<void()> releaseOxygen) {
        unique_lock<mutex>locker(mtx);
        cv.wait(locker,[&]{return cntH==2;});
        releaseOxygen();
        cntH=0;
        cv.notify_all();
    }
};


//原子操作
class H2O {
    atomic<int>h=0;
public:
    H2O() {
    }
    void hydrogen(function<void()> releaseHydrogen) {
        while(h==2){
            this_thread::yield();
        }
        releaseHydrogen();
        ++h;
    }
    void oxygen(function<void()> releaseOxygen) {
        while(h!=2){
            this_thread::yield();
        }
        releaseOxygen();
        h=0;
    }
};