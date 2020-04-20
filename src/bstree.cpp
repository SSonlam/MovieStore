#include "bstree.h"

//constructors
BSTree::BSTree()
{
}

BSTree::~BSTree()
{
    makeEmpty();
}

//----------------------------------------------------------------------------
//function to insert a Movie* into the binary tree, sets first value
//as the Root then sorts future Data going to the Left subtree is value
//is smaller, and to the Right if value is higher
bool BSTree::insert(Movie*& Input) {
    auto Ptr = new Node;
    if (Ptr == nullptr) return false;            // out of memory
    Ptr->Data = Input;
    Ptr->Left = Ptr->Right = nullptr;
    if (isEmpty()) { //empty tree sets Root to first client pointer
        Root = Ptr;
    }
    else {
        Node* Current = Root; // walking pointer
        bool Inserted = false;                 // whether inserted yet
        // if item is less than Current item, insert in Left subtree,
        // otherwise insert in Right subtree
        while (!Inserted) {
            if (*Ptr->Data < *Current->Data) {
                if (Current->Left == nullptr) {              // insert Left
                    Current->Left = Ptr;
                    Inserted = true;
                }
                else
                    Current = Current->Left;               // one step Left
            }
            else {
                if (Current->Right == nullptr) {             // insert Right
                    Current->Right = Ptr;
                    Inserted = true;
                }
                else
                    Current = Current->Right;              // one step Right
            }
        }
    }
    return true;
}

//----------------------------------------------------------------------------
//check Root to see if is nullptr
bool BSTree::isEmpty() const {
    if (!Root) { return true; }
    return false;
}

//----------------------------------------------------------------------------
//recursively prints all nodes of the binary tree
void BSTree::display()const {
    displayHelper(Root);
}

//----------------------------------------------------------------------------
void BSTree::displayHelper(Node* Ptr)const {
    //check for empty tree
    if (Root == nullptr) {
        cout << "The tree is empty" << endl;
    }
    else {
        if (Ptr->Left != nullptr) {
            displayHelper(Ptr->Left);
        }

        cout << *Ptr->Data << endl;

        if (Ptr->Right != nullptr) {
            displayHelper(Ptr->Right);
        }
    }
}



//----------------------------------------------------------------------------
//function to retrieve reference of movie pointer, stores to second param
bool BSTree::retrieveComedy(const string InputName, Movie*& PtrHolder) const {
    //check to see empty tree
    if (!Root) {
        cout << "Cannot perform retrieve, tree is empty" << endl;
        return false;
    }
    //check to see if Root is matching movies
    if (InputName == Root->Data->getTitle()) {
        PtrHolder = Root->Data;
        return true;
    }

    Node* Current = Root; // starts Current at Root
    //iterates through tree to try to find movie
    while (Current) {
        if (InputName.compare(Current->Data->getTitle()) == 0) {
            PtrHolder = Current->Data;
            return true;
        }

        if (InputName.compare(Current->Data->getTitle()) < 0) {
            Current = Current->Left;               // one step Left
        }
        else {
            Current = Current->Right;              // one step Right
        }

    }
    PtrHolder = nullptr;
    //false if cannot find after iteration of tree
    return false;
}

bool BSTree::retrieveClassic(const int InputYear, const int InputMonth,
    string ActorFirst, string ActorLast, Movie*& PtrHolder) const {
    //check to see empty tree
    if (!Root) {
        cout << "Cannot perform retrieve, tree is empty" << endl;
        return false;
    }
    //check to see if Root is matching movies
    if (Root->Data->getActorFirst().compare(ActorFirst) == 0 &&
        Root->Data->getActorLast().compare(ActorLast) == 0 &&
        Root->Data->getReleaseYear() == InputYear &&
        Root->Data->getReleaseMonth() == InputMonth) {
        PtrHolder = Root->Data;
        return true;
    }
    Node* Current = Root; // starts Current at Root
    //iterates through tree to try to find client
    while (Current) {
        if (Current->Data->getActorFirst().compare(ActorFirst) == 0 &&
            Current->Data->getActorLast().compare(ActorLast) == 0 &&
            Current->Data->getReleaseYear() == InputYear &&
            Current->Data->getReleaseMonth() == InputMonth) {

            PtrHolder = Current->Data;
            return true;
        }

        if (InputYear < Current->Data->getReleaseYear()) {
            Current = Current->Left;               // one step Left
        }


        else if (InputYear == Current->Data->getReleaseYear()) {
            if (InputMonth < Current->Data->getReleaseMonth()) {
                Current = Current->Left;
            }
            else {
                Current = Current->Right;
            }
        }


        else {
            Current = Current->Right;              // one step Right
        }

    }
    PtrHolder = nullptr;
    //false if cannot find after iteration of tree
    return false;
}

//----------------------------------------------------------------------------
//function to retrieve reference of movie pointer, stores to second param
bool BSTree::retrieveDrama(const string InputDirector, const string InputTitle,
    Movie*& PtrHolder) const {
    //check to see empty tree
    if (!Root) {
        cout << "Cannot perform retrieve, tree is empty" << endl;
        return false;
    }
    //check to see if Root is matching movies
    if (InputDirector.compare(Root->Data->getDirector()) == 0 &&
        InputTitle.compare(Root->Data->getTitle()) == 0) {
        PtrHolder = Root->Data;
        return true;
    }

    Node* Current = Root; // starts Current at Root
    //iterates through tree to try to find movie
    while (Current) {
        if (InputDirector.compare(Current->Data->getDirector()) == 0 &&
            InputTitle.compare(Current->Data->getTitle()) == 0) {
            PtrHolder = Current->Data;
            return true;
        }

        if (InputDirector.compare(Current->Data->getDirector()) < 0) {
            Current = Current->Left;               // one step Left
        }


        else if (InputDirector.compare(Current->Data->getDirector()) == 0) {
            if (InputTitle.compare(Current->Data->getTitle()) < 0) {
                Current = Current->Left;
            }
            else {
                Current = Current->Right;
            }
        }


        else {
            Current = Current->Right;              // one step Right
        }

    }
    //false if cannot find after iteration of tree
    PtrHolder = nullptr;
    return false;
}


//----------------------------------------------------------------------------
//uses recursion to delete every node of the tree
void BSTree::makeEmpty() {
    makeEmptyHelper(Root);
    Root = nullptr;

}

//----------------------------------------------------------------------------
void BSTree::makeEmptyHelper(Node* Ptr) const {
    if (Ptr == nullptr) return;

    // first delete both subtrees 
    makeEmptyHelper(Ptr->Left);
    makeEmptyHelper(Ptr->Right);

    // then delete the node 
    delete(Ptr->Data);
    delete(Ptr);
}
