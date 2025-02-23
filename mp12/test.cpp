#include "check.h"

using namespace std;

int main(int argc, char** argv){
    cout << " \n\n ------------------- Begin Verifying MP12 ---------------------" << endl;
    int total_score = 0;
    int constructor_score = test_node_constructor();
    
    total_score += constructor_score;

    cout << "Node Constructor Score: " << constructor_score << endl;
    
    int test_set_get_key_score = test_set_key();
    total_score += test_set_get_key_score;

    cout << "Testing Node Set/Get Key Score: " << test_set_get_key_score << endl;

    int test_set_get_data_score = test_set_data();
    total_score += test_set_get_data_score;


    cout << "Testing Node Set/Get Data Score: "<< test_set_get_data_score << endl;

    int test_binary_tree_score = test_binary_tree_constructor();
    total_score += test_binary_tree_score;

    cout << "Testing Binary Tree Constructor Score: " << test_binary_tree_score << endl;
    

    int test_insert_node_score = test_insert_node();
    total_score += test_insert_node_score;

    cout << "Testing Inserting Node and Get Root Score: " << test_insert_node_score << endl;
    

    int test_delete_node_score = test_delete_node();
    total_score += test_delete_node_score;

    
    cout << "Testing Delete Node Score: "<< test_delete_node_score << endl;
    

    int test_find_parent_node_score = test_find_node_parent();
    total_score += test_find_parent_node_score;
    
    cout << "Testing Find Node Parent Score: "<<test_find_parent_node_score  << endl;

    int test_find_node_score = test_find_node();
    total_score += test_find_node_score;


    cout << "Testing Find Node Score:  "<< test_find_node_score << endl;

    int test_sort_word_score = test_sort_word();
    total_score += test_sort_word_score;

    cout << "Testing Sort Word Score:  " << test_sort_word_score << endl;
    

    int test_anagrams_score = test_anagrams();
    total_score += test_anagrams_score;

    cout << "Testing Anagrams Score: " << test_anagrams_score << endl;

    // int total_score = test_anagrams_score + constructor_score + test_set_get_key_score + test_set_get_data_score + test_binary_tree_score + 

    cout << "Total Score: " << total_score << "/100" << endl;

    cout << "-------------------- End Verifying MP12 ----------------------" << endl << endl << endl;


    return 0;
}