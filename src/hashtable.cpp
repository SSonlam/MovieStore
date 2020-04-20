#include "hashtable.h"

//----------------------------class HashTable.cpp------------------------------

HashTable::HashTable()
{
}


HashTable::~HashTable()
{ 
    for (auto X : Deleter) {
        delete X;
    }
}


//adding customer to hash table, does not take duplicate IDs
void HashTable::add(Customer *AddingCustomer) {
    if (doesCustomerExist(AddingCustomer->getID())) { 
        delete AddingCustomer;
        cout << "Customer already exists, adding failed" << endl;
        return; 
    }
    //chaining logic
    int Index = AddingCustomer->getID() % TABLESIZE;
    Table[Index].push_back(AddingCustomer);
    Deleter.push_back(AddingCustomer);
}

//retrieves customer pointer to perform commands on
Customer* HashTable::retrieve(int ID) {
    if (!doesCustomerExist(ID)) { 
        cout << "Customer does not exist, retrieval failed on: " << ID << endl;
        return nullptr; 
    }
    //list iterator 
    list<Customer*>::iterator Itr;
    int Index = ID % TABLESIZE;
    for (Itr = Table[Index].begin(); Itr != Table[Index].end(); Itr++) {
        Customer* Temp = *Itr;
        if (ID == Temp->getID()) {
            return Temp;
        }
    }
    return nullptr;
}

//checks to see if customer exists inside hash table
bool HashTable::doesCustomerExist(int ID) {
    //list iterator 
    list<Customer*>::iterator Itr;
    int Index = ID % TABLESIZE;
    for (Itr = Table[Index].begin(); Itr != Table[Index].end(); Itr++) {
        Customer* Temp = *Itr;
        if (ID == Temp->getID()) {
            return true;
        }
    }
    return false;
}
