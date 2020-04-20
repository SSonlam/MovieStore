/**
 * Testing ass4 movie store functions
 *
 * @author Sonlam Nguyen
 * @3/10/2020
 */

#include "store.h"

#include <cassert>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>

using namespace std;

void testStore1() {
    cout << "Start testStore1" << endl;
    // Should do something more, but lets just read files
    // since each implementation will
    string Cfile = "testcommands-1.txt";
    stringstream Out;
    ifstream Fs(Cfile);
    assert(Fs.is_open());
    char CommandType;
    string Discard;
    while (Fs >> CommandType) {
        Out << CommandType;
        getline(Fs, Discard);
    }
    Fs.close();
    string Result = "IHHBRIBBIH";
    assert(Out.str() == Result);
    cout << "End testStore1" << endl;
}

void testStore2() {
    cout << "Start testStore2" << endl;
    Store MovieStore;
    MovieStore.createCustomers("data4customers.txt");
    MovieStore.readMoviesFromFile("data4movies.txt");
    MovieStore.readCommands("data4commands.txt");
    cout << "End testStore2" << endl;
}

void testStoreFinal() {
    cout << "=====================================" << endl;
    cout << "Start testStoreFinal" << endl;
    cout << "End testStoreFinal" << endl;
    cout << "=====================================" << endl;
}

void testAll() {
    testStore1();
    testStore2();
    testStoreFinal();
}
