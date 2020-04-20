#ifndef BORROW_H
#define BORROW_H

//----------------------------class Borrow.hpp------------------------------

class Borrow : public Command
{
public:
    Command *create() override { return new Borrow(); }

    //assumes correct formatting
    bool read(istream &InputStream) override{
        InputStream >> ClientID >> MediaType >> MovieType;
        switch (MovieType) {
        case 'C': {
            InputStream >> ReleaseMonth;
            InputStream >> ReleaseYear;
            InputStream >> MajorActorFirst;
            InputStream >> MajorActorLast;
            break;
        }
        case 'D': {
            Director = readNextItem(InputStream);
            Title = readNextItem(InputStream);
            break;
        }
        case 'F': {
            Title = readNextItem(InputStream);
            InputStream >> ReleaseYear;
            break;
        }
        default: {
            cout << "invalid movie type: " << MovieType << endl;
            discardLine(InputStream);
            return false;
        }
        }
        return true;
    }

    //finds movie from binary tree
    //subtracts one from inventory, and adds to customer's history
    bool executeBorrow(char CommandType, Customer *&InputCustomer,
        BSTree *&InputTree) override {

        Movie* TempMovie = nullptr;
        
        switch (MovieType) {   
        case 'F':
            InputTree->retrieveComedy(getTitle(), TempMovie);
            break;
        case 'C':
            InputTree->retrieveClassic(getReleaseYear(), getReleaseMonth(),
                getActorFirst(), getActorLast(), TempMovie);
            break;
        case 'D':
            InputTree->retrieveDrama(getDirector(), getTitle(), TempMovie);
            break;
        default:
            cout << "No such movie in inventory to perform a borrow on" << endl;
            return false;
        }

        //movie has to be in inventory
        if (TempMovie != nullptr) {
            bool StockCheck = TempMovie->stockBorrowed();
            if (StockCheck) {
                InputCustomer->addToHistory(CommandType, TempMovie);
                return true;
            }
            cout << "Unable to borrow movie, none in stock: "
                << *TempMovie << endl;
        }      
        return false;
    }

    //irrelevent, polymorphism forces to write
    bool executeReturn(char, Customer *&, BSTree *&) override {
        return false;
    }

    bool executeInventory(map<char, BSTree*>) override {
        return false;
    }
    bool executeHistory(Customer *&) override {
        return false;
    }
};
#endif