#include "check.h"
#include<iostream>
#include<cmath>
#include<string>
#include<algorithm>
#include<fstream>
#include <iomanip>


using namespace std;
int test_node_constructor(){
    int score = 0;
    Node<int,string> test_node1(1, "test");
    GNode<int, string> Gtest_node1(1, "test");

    Node<string, string> test_node2("red", "is_sus");
    GNode<string, string> Gtest_node2("red", "is_sus");

    Node<double,double> test_node3(1.203984, 12.2312321);
    GNode<double, double> Gtest_node3(1.203984, 12.2312321);

    Node<string, long> test_node4("abcdefghijklmnopqrstuvwxyz", 12345678912345);
    GNode<string, long> Gtest_node4("abcdefghijklmnopqrstuvwxyz", 12345678912345);
    if((Gtest_node1 == test_node1)){
        score+=1;
    }

    if((Gtest_node2 == test_node2) ){
        score+=1;
    }

    if((Gtest_node3 == test_node3) && (Gtest_node4 == test_node4)){
        score+=1;
    }

    return score;
}

int test_set_key(){
    int score = 0;
    Node<int, string> test_node(1,"test");
    test_node.setKey(2);
    if(test_node.getKey() == 2){
        score+=2;
    }
    Node<string, string> test_node2("red", "is sus");
    test_node2.setKey("Blue");

    if(test_node2.getKey() == "Blue"){
        score+=2;
    }

    Node<double, double> test_node3(3.14159265,1234.1234);
    test_node3.setKey(1234.1234);
    Node<string, long> test_node4("uwu", 12345678912345);
    test_node4.setKey("UWU");

    if(test_node3.getKey() == 1234.1234 && test_node4.getKey() == "UWU"){
        score+=2;
    }
    return score;
}

int test_set_data(){
    int score = 0;
    Node<int, string> test_node(1,"test");
    test_node.setData("This is a very long message that I am testing");
    if(test_node.getData() == "This is a very long message that I am testing"){
        score += 2;
    }

    Node<string, string> test_node2("red", "is sus");
    test_node2.setData("is not sus");
    if(test_node2.getData() == "is not sus"){
        score += 2;
    }

    Node<double, double> test_node3(3.14159265,1234.1234);
    test_node3.setData(3.14159265);
    Node<string, long> test_node4("uwu", 12345678912345);
    test_node4.setData(1);

    if(test_node3.getData() == 3.14159265 && test_node4.getData() == 1 ){
        score += 2;
    }

    return score;
}

int test_binary_tree_constructor(){
    int score = 0;
    BinaryTree<int, string> test_tree;
    GBinaryTree<int, string> test_treeGold;

    if(test_treeGold == test_tree){
        score += 3;
    }
    
    return score;
}

int test_insert_node(){
    int score = 0;
    BinaryTree<int, string> test_tree;
    GBinaryTree<int, string> test_tree_gold;
    Node<int, string> *test_node = new Node<int, string>(1, "test");
    GNode<int, string> *test_node_gold = new GNode<int, string>(1, "test");
    Node<int, string> *test_node2 = new Node<int, string>(3, "This is a really long text");
    GNode<int, string> *test_node_gold2 = new GNode<int, string>(3, "This is a really long text");
    Node<int, string> *test_node3 = new Node<int, string>(-1, "Among us is fun");
    GNode<int, string> *test_node_gold3 = new GNode<int, string>(-1, "Among us is fun");
    Node<int, string> *test_node4 = new Node<int, string>(2, "12345678910111213141516171819");
    GNode<int, string> *test_node_gold4 = new GNode<int, string>(2, "12345678910111213141516171819");
    
    test_tree.insert_node(test_tree.getRoot(), test_node);
    test_tree_gold.insert_node(test_tree_gold.getRoot(), test_node_gold);
    test_tree.insert_node(test_tree.getRoot(), test_node2);
    test_tree_gold.insert_node(test_tree_gold.getRoot(), test_node_gold2);
    test_tree.insert_node(test_tree.getRoot(), test_node3);
    test_tree_gold.insert_node(test_tree_gold.getRoot(), test_node_gold3);
    test_tree.insert_node(test_tree.getRoot(), test_node4);
    test_tree_gold.insert_node(test_tree_gold.getRoot(), test_node_gold4);

    if(test_tree_gold == test_tree){
        score += 11;
    }

    return score;
}

int test_find_node_parent(){
    int score = 0;
    BinaryTree<int, string> test_tree;
    GBinaryTree<int, string> test_tree_gold;
    Node<int, string> *test_node = new Node<int, string>(1, "test");
    GNode<int, string> *test_node_gold = new GNode<int, string>(1, "test");
    Node<int, string> *test_node2 = new Node<int, string>(3, "This is a really long text");
    GNode<int, string> *test_node_gold2 = new GNode<int, string>(3, "This is a really long text");
    Node<int, string> *test_node3 = new Node<int, string>(-1, "Among us is fun");
    GNode<int, string> *test_node_gold3 = new GNode<int, string>(-1, "Among us is fun");
    Node<int, string> *test_node4 = new Node<int, string>(2, "12345678910111213141516171819");
    GNode<int, string> *test_node_gold4 = new GNode<int, string>(2, "12345678910111213141516171819");
    
    test_tree.insert_node(test_tree.getRoot(), test_node);
    test_tree_gold.insert_node(test_tree_gold.getRoot(), test_node_gold);
    test_tree.insert_node(test_tree.getRoot(), test_node2);
    test_tree_gold.insert_node(test_tree_gold.getRoot(), test_node_gold2);
    test_tree.insert_node(test_tree.getRoot(), test_node3);
    test_tree_gold.insert_node(test_tree_gold.getRoot(), test_node_gold3);
    test_tree.insert_node(test_tree.getRoot(), test_node4);
    test_tree_gold.insert_node(test_tree_gold.getRoot(), test_node_gold4);

    if(test_tree.find_node_parent(1) != NULL || test_tree.find_node_parent(0) != NULL){
        score += 0;
    }else{
        score += 1;
    }


    if(!(*test_tree_gold.find_node_parent(3) == *test_tree.find_node_parent(3))){
        score += 0;
    }else{
        score += 1;
    }

    if(!(*test_tree_gold.find_node_parent(-1) == *test_tree.find_node_parent(-1)) || !(*test_tree_gold.find_node_parent(2) == *test_tree.find_node_parent(2))){
        score += 0;
    }else{
        score += 1;
    }
    return score;
}

int test_find_node(){
    int score = 0;
    BinaryTree<int, string> test_tree;
    GBinaryTree<int, string> test_tree_gold;
    Node<int, string> *test_node = new Node<int, string>(1, "test");
    GNode<int, string> *test_node_gold = new GNode<int, string>(1, "test");
    Node<int, string> *test_node2 = new Node<int, string>(3, "This is a really long text");
    GNode<int, string> *test_node_gold2 = new GNode<int, string>(3, "This is a really long text");
    Node<int, string> *test_node3 = new Node<int, string>(-1, "Among us is fun");
    GNode<int, string> *test_node_gold3 = new GNode<int, string>(-1, "Among us is fun");
    Node<int, string> *test_node4 = new Node<int, string>(2, "12345678910111213141516171819");
    GNode<int, string> *test_node_gold4 = new GNode<int, string>(2, "12345678910111213141516171819");
    
    test_tree.insert_node(test_tree.getRoot(), test_node);
    test_tree_gold.insert_node(test_tree_gold.getRoot(), test_node_gold);
    test_tree.insert_node(test_tree.getRoot(), test_node2);
    test_tree_gold.insert_node(test_tree_gold.getRoot(), test_node_gold2);
    test_tree.insert_node(test_tree.getRoot(), test_node3);
    test_tree_gold.insert_node(test_tree_gold.getRoot(), test_node_gold3);
    test_tree.insert_node(test_tree.getRoot(), test_node4);
    test_tree_gold.insert_node(test_tree_gold.getRoot(), test_node_gold4);

    if(test_tree.find_node(0) != NULL){
        score += 0;
    }else{
        score += 1;
    }
    if(!(*test_tree_gold.find_node(1) == *test_tree.find_node(1))){
        score += 0;
    }else{
        score += 1;
    }
    if(!(*test_tree_gold.find_node(3) == *test_tree.find_node(3)) || !(*test_tree_gold.find_node(-1) == *test_tree.find_node(-1)) ||!(*test_tree_gold.find_node(2) == *test_tree.find_node(2)) ){
        score += 0;
    }else{
        score += 1;
    }

    return score;
}



int test_delete_node(){
    int score = 0;
    BinaryTree<int, string> test_tree;
    GBinaryTree<int, string> test_tree_gold;
    Node<int, string> *test_node = new Node<int, string>(1, "test");
    GNode<int, string> *test_node_gold = new GNode<int, string>(1, "test");
    Node<int, string> *test_node2 = new Node<int, string>(3, "This is a really long text");
    GNode<int, string> *test_node_gold2 = new GNode<int, string>(3, "This is a really long text");
    Node<int, string> *test_node3 = new Node<int, string>(-1, "Among us is fun");
    GNode<int, string> *test_node_gold3 = new GNode<int, string>(-1, "Among us is fun");
    Node<int, string> *test_node4 = new Node<int, string>(2, "12345678910111213141516171819");
    GNode<int, string> *test_node_gold4 = new GNode<int, string>(2, "12345678910111213141516171819");
    
    test_tree.insert_node(test_tree.getRoot(), test_node);
    test_tree_gold.insert_node(test_tree_gold.getRoot(), test_node_gold);
    test_tree.insert_node(test_tree.getRoot(), test_node2);
    test_tree_gold.insert_node(test_tree_gold.getRoot(), test_node_gold2);
    test_tree.insert_node(test_tree.getRoot(), test_node3);
    test_tree_gold.insert_node(test_tree_gold.getRoot(), test_node_gold3);
    test_tree.insert_node(test_tree.getRoot(), test_node4);
    test_tree_gold.insert_node(test_tree_gold.getRoot(), test_node_gold4);

    test_tree.delete_node(1);
    test_tree_gold.delete_node(1);

    if(!(test_tree_gold == test_tree)){
        score += 0;
    }else{
        score += 1;
    }

    test_tree.delete_node(-1);
    test_tree_gold.delete_node(-1);
    if(!(test_tree_gold == test_tree)){
        score += 0;
    }else{
        score += 1;
    }


    test_tree.delete_node(3);
    test_tree_gold.delete_node(3);
    if(!(test_tree_gold == test_tree)){
        score += 0;
    }else{
        score += 1;
    }

    return score;
}

int test_sort_word(){
    int score = 0;
    GAnagramDict gold_dictionary("test1");
    AnagramDict dictionary("test1");

    if(gold_dictionary.sortWord("zabdfaejfitghqaldjfga") == dictionary.sortWord("zabdfaejfitghqaldjfga")){
        score += 3;
    }

    return score;
}

int test_anagrams(){
    int score = 0;
    GAnagramDict gold_dictionary("test1.txt");
    AnagramDict dictionary("test1.txt");


    if(gold_dictionary == dictionary){
        score += 3;
        score += 8;
        score += 7;
    }

    return score;
}