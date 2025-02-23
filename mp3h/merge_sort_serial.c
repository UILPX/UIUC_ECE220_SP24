#include "merge_sort.h"



int main() {
    Node* head = make_ll_from_file("input.txt");

    // @TODO insert your code here

    print_list(head,"serial_output.txt");
    free_list(head);
    return 0;
}
