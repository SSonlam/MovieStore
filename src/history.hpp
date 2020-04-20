#ifndef HISTORY_H
#define HISTORY_H

class History : public Command
{
public:
    Command *create() override { return new History(); }

    //reads in customer ID
    bool read(istream &InputStream) override{
        InputStream >> ClientID;
        return true;
    }

    //tells customer to print entire history log
    bool executeHistory(Customer *&InputCustomer) override {
        if (InputCustomer != nullptr) {
            cout << "Customer history for: " << *InputCustomer << endl;
                InputCustomer->printHistory();
                return true;
        }
        return false;
    }

    //irrelevant, forced to implement
    bool executeInventory(map<char, BSTree*>) override{
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