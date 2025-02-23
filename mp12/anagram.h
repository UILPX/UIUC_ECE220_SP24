#ifndef ANAGRAM_H_
#define ANAGRAM_H_

#include "binary.h"
#include <string>
#include <list>
#include <iterator>
#include <fstream>
#include <algorithm>


/***
An AnagramDict Class

This class utilizes a binary tree to 
create a dictionary of anagrams. Where each tree node contains
a key that is a sorted string and a list to represent all the anagrams
that fall under that sorted string.

***/
class AnagramDict {
    public:
    AnagramDict(std::string filename);
    std::string sortWord(std::string word);
    void addWord(std::string word);
    void saveAnagrams(std::string order);
    BinaryTree<std::string, std::list<std::string> > tree;
    std::string filename_;
};


#endif