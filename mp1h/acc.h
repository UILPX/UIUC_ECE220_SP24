#include "thread_info.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef NUM_THREADS
    #define NUM_THREADS 4 // [1, 99]
#endif

#define FILE_NAME_LEN 22

const char* FILE_NAME_PREFIX = "input/acc_input.part";

// a piece of global memory for argument passing and to hold intermediate sums returned by each thread
unsigned long long thread_mem[NUM_THREADS];

/**
 * Read and compute the sum of all numbers within the file "input/acc_input.part##"
 * @param  thread_id File index
 * @return   Sum of all numbers within the file
 */
unsigned long long acc_file(int thread_id) {
    unsigned long long result = 0;

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
        result += atoi(buf);
    }

    fclose(in);

    // Return calculated sum
    return result;
}

/**
 * A pthread compatible wrapper that calls acc_file
 * @param  arg Pointer to thread's ID
 * @return     NULL
 */
void *parallel_acc_wrapper(void *arg) {
    // Get the thread ID from void pointer
    int thread_id = *(int *) arg;

    // Calculate result with acc_file, then store in thread_mem
    unsigned long long result = acc_file(thread_id);
    thread_mem[thread_id] = result;
}
