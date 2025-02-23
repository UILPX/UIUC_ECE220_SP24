#ifndef GANAGRAM_H_
#define GANAGRAM_H_

#include "Gbinary.h"
#include "anagram.h"
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
class GAnagramDict {
    public:
        GAnagramDict(std::string filename);
        std::string sortWord(std::string word);
        void addWord(std::string word);
        void saveAnagrams(std::string order);
        bool operator==(AnagramDict &rhs);

        
        
        GBinaryTree<std::string, std::list<std::string> > tree;
        std::string filename_;

};


#endif