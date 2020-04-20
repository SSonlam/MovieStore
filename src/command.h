#ifndef COMMAND_H
#define COMMAND_H

#include "bstree.h"
#include "customer.h"
#include "movie.h"

#include <iostream>
#include <iterator>
#include <map>
#include <string>
#include <vector>

using namespace std;

//-----------------------------header Command.h-------------------------------

class Command{
public:
    virtual Command *create() = 0;
    virtual bool read(istream &is) = 0;
    virtual bool executeInventory(map<char, BSTree*> TempMap) = 0;
    virtual bool executeHistory(Customer *&inputCustomer) = 0;
    virtual bool executeBorrow(char CommandType, Customer *&InputCustomer,
        BSTree *&InputTree) = 0;
    virtual bool executeReturn(char CommandType, Customer *&InputCustomer,
        BSTree *&InputTree) = 0;
    int getClientID();
    int getReleaseYear();
    int getReleaseMonth();
    string getTitle();
    string getActorFirst();
    string getActorLast();
    string getDirector();
    char getMovieType();
    string readNextItem(istream &InputStream, char Delimiter = ',');
    const string discardLine(istream &InputStream);
    virtual ~Command() = default;

protected:
    int ClientID;
    char MediaType;
    char MovieType;
    int ReleaseYear;
    int ReleaseMonth;
    string Director;
    string Title;
    string MajorActorFirst;
    string MajorActorLast;
};
#endif
