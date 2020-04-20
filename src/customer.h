#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "movie.h"

#include <string>
#include <vector>

using namespace std;

//-----------------------------header Customer.h-------------------------------

class Customer
{
public:
    friend ostream& operator<<(ostream& OutStream, const Customer& TempCustomer);
    Customer();
    Customer(int ID, string LName, string FName);
    ~Customer() = default;
    void addToHistory(char CommandType, Movie* TempMovie);
    void printHistory();
    int getID();
    vector<string> History;
private:
    int CustomerID;
    string LastName;
    string FirstName;
};
#endif
