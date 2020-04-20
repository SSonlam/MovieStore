#ifndef COMMANDFACTORY_H
#define COMMANDFACTORY_H

#include "borrow.hpp"
#include "command.h"
#include "history.hpp"
#include "inventory.hpp"
#include "return.hpp"

#include <iostream>
#include <vector>

//-----------------------class CommandFactory.hpp------------------------------

class CommandFactory
{
public:
    CommandFactory() = default;
    virtual ~CommandFactory() = default;

    //Only commands within the switch case can be created
    Command *create(char CommandType) {
        switch (CommandType) {
        case 'B': {
            Commands = new Borrow();
            break;
        }
        case 'R': {
            Commands = new Return();
            break;
        }
        case 'H': {
            Commands = new History();
            break;
        }
        case 'I': {
            Commands = new Inventory();
            break;
        }
        default: {
            delete Commands;
            cout << "invalid command type: " << CommandType << endl;
            return nullptr;
        }
        }
         return Commands->create();
    }

private:
    Command *Commands;
};
#endif
