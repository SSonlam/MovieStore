#include "store.h"

//----------------------------class Store.cpp------------------------------

Store::Store()
{
    Inventory['F'] = new BSTree();
    Inventory['D'] = new BSTree();
    Inventory['C'] = new BSTree();
}

Store::~Store()
{
    Inventory['C']->makeEmpty();
    Inventory['D']->makeEmpty();
    Inventory['F']->makeEmpty();
}

bool Store::createCustomers(const string &FileName) {
    //read in file with expected formatting
        ifstream InFile;
        InFile.open(FileName);
        if (!InFile) {
            cout << "Failure opening file";
        }

        int ID;
        string LastName;
        string FirstName;

        //expected we know file formatting already
        while (InFile >> ID >> LastName >> FirstName) {
            Customer *StoreCustomer = new Customer(ID, LastName, FirstName);
            CustomerTable.add(StoreCustomer);
        }

        InFile.close();
        return true;
    }


bool Store::readMoviesFromFile(const string &FileName) {
    ifstream InFile;
    InFile.open(FileName);
    if (!InFile) {
        cout << "Failure opening file";
        exit(1);
    }
    char MovieType;
    while (InFile >> MovieType) {
        Movie *TempMovie = Factory.create(MovieType);
        if (TempMovie) {
            if (TempMovie->read(InFile)) {
                Inventory[MovieType]->insert(TempMovie);
            }
        }
        else {
            TempMovie->discardLine(InFile);
            delete TempMovie;
            cout << "Invalid movie, discarded line" << endl;
        }
    }
    
    return true;
}

bool Store::readCommands(const string &FileName) {
    ifstream InFile;
    InFile.open(FileName);
    if (!InFile) {
        cout << "Failure opening file";
        exit(1);
    }
    char CommandType;
    while (InFile >> CommandType) {
        Command *TempCommand = CFactory.create(CommandType);
        if (TempCommand) {
            if (TempCommand->read(InFile)) {
                Customer* TempCustomer;
                    switch (CommandType) {
                    case 'B':
                        TempCustomer = CustomerTable.
                            retrieve(TempCommand->getClientID());
                        if (TempCustomer != nullptr) {
                            TempCommand->executeBorrow(CommandType,
                                TempCustomer, Inventory[TempCommand->
                                getMovieType()]);
                        }
                        break;

                    case 'R':
                        TempCustomer = CustomerTable.retrieve
                        (TempCommand->getClientID());
                        if (TempCustomer != nullptr) {
                            TempCommand->executeReturn(CommandType,
                                TempCustomer, Inventory[TempCommand->
                                getMovieType()]);
                        }
                        break;

                    case 'H':
                        TempCustomer = CustomerTable.retrieve
                        (TempCommand->getClientID());

                        if (TempCustomer != nullptr) {
                            TempCommand->executeHistory(TempCustomer);
                        }
                        break;

                    case 'I':
                        TempCommand->executeInventory(Inventory);
                        break;
                    default:
                        cout << "Unrecognized command, will not perform: "
                            << CommandType << endl;
                        break;

                    }
                    delete TempCommand;
            }
        }
        else {
            TempCommand->discardLine(InFile);
        }
    }
    return true;
}