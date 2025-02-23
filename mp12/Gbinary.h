#ifndef GBINARY_H_
#define GBINARY_H_

#include<iostream>
#include<cmath>
#include<string>
#include<algorithm>
#include<list>
#include<fstream>
#include<iomanip>
#include "binary.h"

/***
A Single Tree Node Class

This class contains a templated key and data. 
This allows for the data the tree uses to be
various data types. Please implement the Node's
constructor, getKey, setKey, getData and setData
functions. 
***/
template <class T, class Y>
class GNode{
    public:
        GNode<T, Y> (T key, Y data);
        T getKey();
        void setKey(T key);
        Y getData();
        void setData(Y data);

        bool operator==( Node<T,Y> &rhs) const;

        GNode<T, Y> *left;
        GNode<T, Y> *right;

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
class GBinaryTree{

    public:
        GBinaryTree();
        ~GBinaryTree();
        void insert_node(GNode<T,Y> *parent_node,GNode<T,Y> *data);
        GNode<T,Y> * find_node_parent(T key);
        GNode<T,Y> * find_node(T key);
        void delete_node(T key);
        void pre_order(GNode<T,Y> *node, std::list<GNode<T,Y> > &list);
        void in_order(GNode<T,Y> *node, std::list<GNode<T,Y> > &list);
        void post_order(GNode<T,Y> *node, std::list<GNode<T,Y> > &list);
        GNode<T,Y> * getRoot();
        bool operator==( BinaryTree<T,Y> &rhs);

    private:
        GNode<T,Y> *root;
        GNode<T,Y> * find_node_parent(GNode<T,Y> *node,T key);
        GNode<T,Y> * find_node(GNode<T,Y> *node,T key);
        GNode<T,Y> * delete_node(GNode<T,Y>* node, T key);

};

#endif