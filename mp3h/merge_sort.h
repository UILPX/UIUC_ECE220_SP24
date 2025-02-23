#pragma once

#include "ll.h"


Node* split_ll(Node* in, int* length);
Node* merge_ordered_ll(Node* heada, Node* headb);
Node* merge_sort(Node* head);
void *parallel_merge_sort_wrapper(void *arg);