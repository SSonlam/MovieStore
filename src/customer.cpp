#include "customer.h"

using namespace std;

//-----------------------------class Customer.cpp-------------------------------

Customer::Customer()
{
}

Customer::Customer(int ID, string LName, string FName) {
   CustomerID = ID;
   LastName = LName;
   FirstName = FName;
}

//cout overloader
ostream& operator<<(ostream& OutStream, const Customer& TempCustomer) {
    OutStream << TempCustomer.CustomerID << " " << TempCustomer.LastName
        << " " << TempCustomer.FirstName;
    return OutStream;
}

//getter
int Customer::getID() {
    return CustomerID;
}

//adds a string in sentence format to a customer's history log vector
void Customer::addToHistory(char CommandType, Movie* TempMovie) {
    string Line;
    switch (CommandType) {
    case 'B':
        Line = "Borrowed: " + TempMovie->getTitle() + " " + TempMovie->getDirector()
            + " " + TempMovie->getActorFirst() + " " + TempMovie->getActorLast();
        break;
    case 'R':
        Line = "Returned: " + TempMovie->getTitle() + " " + TempMovie->getDirector()
            + " " + TempMovie->getActorFirst() + " " + TempMovie->getActorLast();
    default:
        break;
    }
    History.push_back(Line);
}
//prints out the customer's entire history
void Customer::printHistory() {
    int TempSize = History.size();
    if (TempSize > 0) {
        for (int I = 0; I < TempSize; I++) {
            cout << History[I] << endl;
        }
    }
    cout << endl;
}
