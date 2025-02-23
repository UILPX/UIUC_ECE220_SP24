#include "acc.h"
#include <pthread.h>

int main() {
    unsigned long long ret = 0;

    // Holds pthread_t's for all generated threads
    pthread_t threads[NUM_THREADS];

    // Holds thread id's for all generated threads
    int thread_args[NUM_THREADS];

    // Temporary thread_id for looping purposes
    int thread_id;

    // Loop to create NUM_THREADS threads with pthread_create (Your code goes here)
    for () {
        // Since parallel_acc_wrapper only accepts a pointer (instead of an int),
        // all values of thread_id must be stored in an array, otherwise the pointer
        // passed to this function will not retain its value when the function fetches it
        thread_args[thread_id] = thread_id;
        void *thread_arg = &thread_args[thread_id]; // a pointer to thread_args[thread_id]

        // Create the new thread (Your code goes here)

    }

    // Wait for all threads to complete and join them (Your code goes here)
    for () {

        // Fetch the thread's result from thread_mem, add it to our return value (Your Code Goes Here)
        
    }

    // Write the calculated result to parallel_output.txt
    FILE *out = fopen("parallel_output.txt", "w");
    fprintf(out, "%llu\n", ret);
    fclose(out);
    
    return 0;
}
