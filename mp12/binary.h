#ifndef BINARY_H_
#define BINARY_H_

#include<iostream>
#include<cmath>
#include<string>
#include<algorithm>
#include<list>
#include<fstream>
#include <iomanip>

/***
A Single Tree Node Class

This class contains a templated key and data. 
This allows for the data the tree uses to be
various data types. Please implement the Node's
constructor, getKey, setKey, getData and setData
functions. 
***/
template <class T, class Y>
class Node{
    public:
        Node<T, Y> (T key, Y data);
        T getKey();
        void setKey(T key);
        Y getData();
        void setData(Y data);
        Node<T, Y> *left;
        Node<T, Y> *right;

    private:
        T key_;
        Y data_;
};

/***
A Binary Tree Class

This class contains a templated key and data. 
This allows for the data the tree uses to be
various data types. This Class will implement 
various functions for a binary tree. Please 
implement the Trees constructor, destructor,
insert_node, find_node_parent, find_node, 
delete_node, pre_order, post_order, in_order,
and getRoot functions.

***/
template <class T, class Y>
class BinaryTree{

    public:
        BinaryTree();
        ~BinaryTree();
        void insert_node(Node<T,Y> *parent_node,Node<T,Y> *data);
        Node<T,Y> * find_node_parent(T key);
        Node<T,Y> * find_node(T key);
        void delete_node(T key);
        void pre_order(Node<T,Y> *node, std::list<Node<T,Y> > &list);
        void in_order(Node<T,Y> *node, std::list<Node<T,Y> > &list);
        void post_order(Node<T,Y> *node, std::list<Node<T,Y> > &list);
        Node<T,Y> * getRoot();

    private:
        Node<T,Y> *root;
        Node<T,Y> * find_node_parent(Node<T,Y> *node,T key);
        Node<T,Y> * find_node(Node<T,Y> *node,T key);
        Node<T,Y> * delete_node(Node<T,Y>* node, T key);

};



#endif