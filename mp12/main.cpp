#include "anagram.h"


int main(int argc, char** argv){
    if (argc < 3)
    {
        printf("You need a valid dictionary file and order.\n");
        return -1;
    }
    printf("Creating dictionary with file %s\n", argv[1]);


    AnagramDict my_test(argv[1]);

    printf("Traversing using %s order\n", argv[2]);
    my_test.saveAnagrams(argv[2]);
    return 0;
}