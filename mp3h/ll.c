#include "ll.h"


/*
    Creates a new node with value equal to new_val in heap memory

    ARGS:
        int new_val -> the val of the new node
    RET:
        pointer to the new allocated node
*/
Node* make_node(int new_val) {
  // @TODO insert your code here
  return NULL;
}

/*
    allocate and insert a new node at the head of a linked list

    ARGS:
        int new_val -> value of the new node
        head        -> double pointer to the memory location holding the address of head node (the content of this pointer will be modified)
    RET:
        Nothing
*/
void insert_at_head(int new_val, Node** head) {
  // @TODO insert your code here
}

/*
    free the heap memory used by the linked list

    ARGS:
        Node* in -> pointer of linked list head (the memory pointed will be freed)
    RET:
        Nothing
*/
void free_list(Node* in) {
  // @TODO insert your code here
}

/*
    create a linked list from an input file

    ARGS:
        const char* file -> the name of the file to be read
    RET:
        head of the created linked list
*/
Node* make_ll_from_file(const char* file) {
    FILE* in = fopen(file, "r");
    if (!in) {
        printf("Bad input! %s\n", file);
        exit(-1);
    }
    Node* head = NULL;
    int num;
    while (1 == fscanf(in, "%d\n", &num)) {
        insert_at_head(num, &head);
    }

    fclose(in);
    return head;
}

/*
    print the content of a linked list to the specified file

    ARGS:
        Node* in -> head of the list
    RET:
        Nothing
*/
void print_list(Node* in, const char* file) {
    FILE* out = fopen(file, "w");
    if (!in) {
        fprintf(out, "Empty!\n");
        fclose(out);
        out = NULL;
        return;
    }
    while (in) {
        fprintf(out, "%d\n", in->val);
        in = in->next;
    }
    fclose(out);
    out = NULL;
}
