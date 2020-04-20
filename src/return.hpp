#ifndef RETURN_H
#define RETURN_H

//----------------------------class return.hpp------------------------------

class Return : public Command
{
public:
    Command *create() override { return new Return(); }
    bool read(istream &is) override{
        is >> ClientID >> MediaType >> MovieType;
        switch (MovieType) {
        case 'C': {
            is >> ReleaseMonth >> ReleaseYear >> MajorActorFirst;
            is >> MajorActorLast;
            break;
        }
        case 'D': {
            Director = readNextItem(is);
            Title = readNextItem(is);
            break;
        }
        case 'F': {
            Title = readNextItem(is);
            is >> ReleaseYear;
            break;
        }
        default: {
            cout << "invalid movie type: " << MovieType << endl;
            discardLine(is);
            return false;
        }
        }
        return true;
    }

    //adds 1 to the inventory then adds to customer's history
    bool executeReturn(char CommandType, Customer *&InputCustomer,
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
        }


        if (TempMovie != nullptr) {
            TempMovie->stockReturned();
            InputCustomer->addToHistory(CommandType, TempMovie);
            return true;
        }
        return false;
    }

    //irrelevent, forced to implement
    bool executeInventory(map<char, BSTree*>) override {
        return false;
    }
    bool executeHistory(Customer *&) override {
        return false;
    }
    bool executeBorrow(char, Customer *&,BSTree *&) override {

        return false;
    }
};
#endif