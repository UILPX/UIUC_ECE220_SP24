#include "merge_sort.h"
#include <pthread.h>

#define THRESHOLD 16384

void* merge_sort_thread_wrapper(void *arg){
    Node* head = (Node*)arg;
    int length = 0;
    Node* new_head = split_ll(head, &length);

    // if number of nodes less than threshold, use sequential version
    if (length < THRESHOLD) {
        head = merge_sort(head);
        new_head = merge_sort(new_head);
        head = merge_ordered_ll(head, new_head);
        pthread_exit((void*)head);
    }

    // @TODO insert your code here
    return NULL;
}



int main() {
    Node* head = make_ll_from_file("input.txt");

    // @TODO insert your code here

    print_list(head,"parallel_output.txt");
    free_list(head);
    return 0;
}
