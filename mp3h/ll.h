#pragma once

#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int val;
    struct Node* next;
} Node;

Node* make_node(int new_val);
void insert_at_head(int new_val, Node** head);
void free_list(Node* in);

Node* make_ll_from_file(const char* file);

void print_list(Node* in, const char* file);