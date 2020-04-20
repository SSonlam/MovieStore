#ifndef BSTREE_H
#define BSTREE_H

#include "movie.h"

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

//-----------------------------class BSTree-----------------------------------

class BSTree {
public:
    BSTree();
    ~BSTree(); // calls makeEmpty which deallocates all memory
   //insert object into the tree, parameter holds pointer to object to insert
    bool insert(Movie*& Input); //insert client pointers binary tree style

    // retrieve functions, first parameter is id to retrieve
    // second parameter holds pointer to found object, nullptr if not found
    // three different retrieves because different veriables needed
    bool retrieveComedy(const string InputName, Movie *&PtrHolder) const;
    bool retrieveClassic(const int InputYear, const int InputMonth,
        string ActorFirst, string ActorLast, Movie*& PtrHolder) const;
    bool retrieveDrama(const string InputDirector, const string InputTitle,
        Movie*& PtrHolder) const;
    bool isEmpty() const; //returns true if tree is empty
    void display() const; //displays the contents of a tree to cout  
    void makeEmpty(); //deletes every node of the tree

private:

    struct Node { //glue that holds data properly
        Movie* Data;
        Node* Right;
        Node* Left;
    };

    Node* Root = nullptr; // root of the tree
    void displayHelper(Node* Ptr) const; //display helper
    void makeEmptyHelper(Node* Ptr) const; //makeEmpty helper
};
#endif

