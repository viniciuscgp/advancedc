/* 
 * File:   Threads.h
 * Author: viniciuscgp
 *
 * Created on February 23, 2022, 6:29 PM
 */

#ifndef THREADS_H
#define THREADS_H
#ifdef __cplusplus
extern "C" {
#endif
    void ThreadsTests();
    static void* counter_mutex_thf(void*);
    static void* counter_thf(void* );
    static void* getprime_thf(void*);
    static void* recebe_bombustivel_thf(void*);
    static void* recebe_bombustivelbroad_thf(void* arg);
    static void* carro_abastece_thf(void*);
    static void* soma5_thf(void*);

#ifdef __cplusplus
}
#endif

#endif /* THREADS_H */

