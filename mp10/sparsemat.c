#include "sparsemat.h"

#include <stdio.h>
#include <stdlib.h>

/*This sparse matrix manipulation program, implemented in C, efficiently handles operations on sparse matrices, 
where the majority of elements are zero. Utilizing a linked list structure to store non-zero elements as tuples 
(row, column, value), it significantly reduces memory usage and computational overhead compared to traditional 
2D array representations. The program supports various operations such as loading matrices from files, adding 
and optionally multiplying matrices, setting or retrieving specific elements, and saving the sparse matrix back 
to a file. By focusing on non-zero elements, it optimizes operations like addition and multiplication, which are 
particularly costly in terms of processing time for dense matrices. This approach not only accelerates computations 
but also offers a scalable solution for handling large datasets that are typical in scientific computations, 
machine learning data sparsity, and graph representations, making it a versatile tool in the computational toolkit.*/



sp_tuples * load_tuples(char* input_file)
{
    int rows,cols;
    FILE *fp = fopen(input_file,"r");//open file
    if(fp == NULL){
        return NULL;
    }
    fscanf(fp,"%d %d", &rows,&cols);//load dimension
    //initialize
    sp_tuples *mat = (sp_tuples *)malloc(sizeof(sp_tuples));
    mat->m = rows;
    mat->n = cols;
    mat->nz = 0;
    mat->tuples_head = NULL;
    //load value
    int row,col;
    double value;
    while(fscanf(fp,"%d %d %lf", &row,&col,&value)==3){
        set_tuples(mat,row,col,value);
    }
    fclose(fp);//close file
    return mat;
}



double gv_tuples(sp_tuples * mat_t,int row,int col)

{
    if(mat_t == NULL){
        return 0;
    }

    sp_tuples_node *current = mat_t->tuples_head;
    while(current != NULL) {// Traverse the linked list
        if(current->row == row && current->col == col){ // Check if the current node matches the requested indices
            return current->value; // Return the value if found
        }
        current = current->next; // Move to the next node in the list
    }

    return 0; // Return 0 if the element is not found (implicitly zero)
}



void set_tuples(sp_tuples * mat_t, int row, int col, double value)
{
    if(mat_t == NULL) return;

    // Pointer to the head of the list
    sp_tuples_node **curr = &(mat_t->tuples_head);
    sp_tuples_node *node_to_delete = NULL;

    // Traverse the list to find the insertion point or the node to update/delete
    while(*curr != NULL && ((*curr)->row < row || ((*curr)->row == row && (*curr)->col < col))) {
        curr = &((*curr)->next);
    }

    // Node exists and needs to be updated or deleted
    if(*curr != NULL && (*curr)->row == row && (*curr)->col == col) {
        if(value == 0) {
            // Delete the node
            node_to_delete = *curr;
            *curr = node_to_delete->next;  // Bypass the deleted node
            free(node_to_delete);
            mat_t->nz--;  // Decrement the count of non-zero elements
        } else {
            // Update the node's value
            (*curr)->value = value;
        }
    } else if(value != 0) {
        // Create and insert a new node for non-zero value
        sp_tuples_node *new_node = malloc(sizeof(sp_tuples_node));
        new_node->row = row;
        new_node->col = col;
        new_node->value = value;
        new_node->next = *curr; // Link the new node to the next node in the list
        *curr = new_node;       // Update the previous node's next pointer
        mat_t->nz++;            // Increment the count of non-zero elements
    }
    return;
}

/*{
    if(value == 0){

    }
    sp_tuples_note *current = mat_t->tuples_head;
    while(current != NULL){
        if(current->row == row && current->col == col){
            mat->value = value;
            return;
        }
        current = current->next;
    }
    return;
}*/



void save_tuples(char * file_name, sp_tuples * mat_t)
{
    // Check if the matrix pointer is valid
    if(mat_t == NULL){
        return;
    }
    // Attempt to open the file for writing
    FILE *file = fopen(file_name, "w");
    if(file == NULL) {
        // Handle the error as appropriate
        perror("Error opening file");
        return;
    }
    
    // Write the dimensions of the matrix
    fprintf(file, "%d %d\n", mat_t->m, mat_t->n);
    
    // Iterate over the linked list and write each non-zero element to the file
    sp_tuples_node *current = mat_t->tuples_head;
    while(current != NULL){
        fprintf(file, "%d %d %lf\n", current->row, current->col, current->value);
        current = current->next;
    }
    
    // Close the file
    fclose(file);
    return;
}



sp_tuples * add_tuples(sp_tuples * matA, sp_tuples * matB){
    // Check for same dimensions
    if(matA->m != matB->m || matA->n != matB->n) return NULL;

    // Create new matrix for result
    sp_tuples *matC = (sp_tuples *)malloc(sizeof(sp_tuples));
    matC->m = matA->m;
    matC->n = matA->n;
    matC->nz = 0; // Will be updated by set_tuples
    matC->tuples_head = NULL;

    // Helper function to add values to matC, creating nodes if necessary
    // Now inline within the loop
    sp_tuples_node *node = matA->tuples_head;
    while(node != NULL){
        double value = gv_tuples(matC, node->row, node->col) + node->value;
        set_tuples(matC, node->row, node->col, value);
        node = node->next;
    }

    node = matB->tuples_head;
    while(node != NULL){
        double value = gv_tuples(matC, node->row, node->col) + node->value;
        set_tuples(matC, node->row, node->col, value);
        node = node->next;
    }

    return matC;
}



/*sp_tuples * mult_tuples(sp_tuples * matA, sp_tuples * matB){ 
    // Verify dimensions for valid matrix multiplication
    if(matA->n != matB->m) return NULL;

    // Initialize matrix C
    sp_tuples *matC = (sp_tuples *)malloc(sizeof(sp_tuples));
    matC->m = matA->m;
    matC->n = matB->n;
    matC->nz = 0;
    matC->tuples_head = NULL;

    // Iterate over each non-zero element of matA
    for(sp_tuples_node *aNode = matA->tuples_head; aNode != NULL; aNode = aNode->next){
        // Iterate over each non-zero element of matB to find matching elements
        for(sp_tuples_node *bNode = matB->tuples_head; bNode != NULL; bNode = bNode->next){
            // Check if the column of matA's element matches the row of matB's element
            if(aNode->col == bNode->row){
                // Get current value in matC at the resulting position
                double valueInC = gv_tuples(matC, aNode->row, bNode->col);
                // Calculate the product and add it to the current value
                double product = aNode->value * bNode->value;
                // Update the value in matC
                set_tuples(matC, aNode->row, bNode->col, valueInC + product);
            }
        }
    }

    return matC;
}*/


	
void destroy_tuples(sp_tuples * mat_t){
    if(mat_t == NULL){
        return;
    }
    // Pointer to traverse the linked list
    sp_tuples_node *current = mat_t->tuples_head;
    sp_tuples_node *next_node = NULL;

    // Loop through the linked list and free each node
    while(current != NULL){
        next_node = current->next; // Store the pointer to the next node
        free(current); // Free the current node
        current = next_node; // Move to the next node
    }

    // Finally, free the structure itself
    free(mat_t);
    return;
}






