//rows and columns should be zero indexed!!

typedef struct sp_tuples_node
{
    double value;
    int row;
    int col;
    struct sp_tuples_node * next;

} sp_tuples_node;


typedef struct sp_tuples //list of coordinate format - each node is a tuple containing row col and value.
{
    int m; //# of rows
    int n; //# of cols
    int nz;//# of non-zero entries in matrix

    sp_tuples_node * tuples_head;
} sp_tuples;


// Read an input file and return a matrix
sp_tuples * load_tuples(char* input_file);

//given a matrix, return the value of the element in the matrix that corresponds to the given coordinates. coordinates are 0 indexed.
double gv_tuples(sp_tuples * mat_t,int row,int col);

//given a matrix, set the value of the element that corresponds to the given coordinates.
void set_tuples(sp_tuples * mat_t, int row, int col, double value);

//Save the matrix to a text file.
void save_tuples(char * file_name, sp_tuples * mat_t);

//return a matrix that is the sum of matA and matB.
sp_tuples * add_tuples(sp_tuples * matA, sp_tuples * matB);

//return a matrix that is the product of matA and matB. Beware that matrix multiplication is not commutative e.g. matA*matB != matB*matA
sp_tuples * mult_tuples(sp_tuples * matA, sp_tuples * matB);

//free any and all allocated space associated with the given matrix.
void destroy_tuples(sp_tuples * mat_t);


