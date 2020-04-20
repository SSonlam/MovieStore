#ifndef STORE_H
#define STORE_H

#include "bstree.h"
#include "command.h"
#include "commandfactory.hpp"
#include "customer.h"
#include "hashtable.h"
#include "movie.h"
#include "moviefactory.hpp"

#include <fstream>
#include <map>
#include <vector>

using namespace std;

//----------------------------header Store.h------------------------------

class Store
{
public:
    Store();
    ~Store();
    bool createCustomers(const string &FileName);
    bool readMoviesFromFile(const string &FileName);
    bool readCommands(const string &FileName);

private:
    HashTable CustomerTable;
    MovieFactory Factory;
    CommandFactory CFactory;
    map<char, BSTree*> Inventory;
};
#endif

