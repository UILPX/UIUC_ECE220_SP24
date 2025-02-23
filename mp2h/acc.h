#include "thread_info.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#ifndef NUM_THREADS
    #define NUM_THREADS 4 // [1, 99]
#endif

#define FILE_NAME_LEN 22

const char* FILE_NAME_PREFIX = "input/acc_input.part";
unsigned long long result = 0;
// @TODO Create a lock


/*
    Read and compute the sum of all numbers within the file "input/acc_input.partxx"

    ARGS:
        int thread_id -> the file index
    RET:
        the sum of all numbers with in the file
*/
unsigned long long acc_file(int thread_id) {
    unsigned long long t_result = 0;

    // Generate file suffix based on thread_id
    char suffix[3];
    sprintf(suffix, "%02d", thread_id);

    // Concatenate FILE_NAME_PREFIX with generated suffix
    char fileName[FILE_NAME_LEN];
    strcpy(fileName, FILE_NAME_PREFIX);
    strcat(fileName, suffix);

    // Open file for reading
    FILE* in = fopen(fileName, "r");
    char buf[63];

    // Read file line-by-line
    while (fgets(buf, 63, in)) {
        // Add converted string to integer value to result
        t_result += atoi(buf);
    }

    fclose(in);

    return t_result;
}

/*
    A pthread compatible wrapper that calls acc_file
    This is the entry point of each thread when calling pthread_create
    
    The input to this funtion should specify the index of the input file for the thread
    This function should call acc_file and accumulate the sub-total into the variable result
    ARGS:
        void* arg -> a pointer to the memory location where the argument is placed
    RET:
        NULL
*/
void *parallel_acc_wrapper(void *arg) {    
    // @TODO insert your code here

    return NULL;
}
