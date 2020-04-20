#ifndef INVENTORY_H
#define INVENTORY_H

#include "bstree.h"

#include <iterator>

class Inventory : public Command
{
public:
    Command *create() override { return new Inventory(); }
    //read for inventory never has anything else after input
    bool read(istream &) override{
        return true;
    }

    //displays all of inventory in order
    bool executeInventory(map<char, BSTree*> TempMap) override {
        cout << "Store Inventory:" << endl;
        TempMap['F']->display();
        TempMap['D']->display();
        TempMap['C']->display();
        cout << endl;
        return true;
    }

    //irreleventm forced to implement
    bool executeHistory(Customer *&) override {
        return false;
    }
    bool executeBorrow(char, Customer *&, BSTree *&) override {
        return false;
    }
    bool executeReturn(char, Customer *&, BSTree *&) override {
        return false;
    }

};
#endif