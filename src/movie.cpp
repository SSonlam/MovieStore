#include "movie.h"

//-----------------------------class Movie.cpp-------------------------------

string Movie::readNextItem(istream &InputStream, char Delimiter) {
    const char Space = ' ';
    string TempString;
    getline(InputStream, TempString, Delimiter);
    if (TempString.empty()) {
        return TempString;
    }
    return TempString.substr(TempString.find_first_not_of(Space),
        TempString.find_last_not_of(Space) + 1);
}

const string Movie::discardLine(istream &InputStream) {
    string Discard;
    getline(InputStream, Discard);
    return Discard;
}

//Stock has to be over 0 to be borrowed
bool Movie::stockBorrowed() {
    if (0 < Stock) {
        --Stock;
        return true;
    }
    return false;
}

//no precondition for returning stock
void Movie::stockReturned() {
    ++Stock;
}

//getters for private variables
string Movie::getTitle() {
    return Title;
}
string Movie::getDirector() {
    return Director;
}
string Movie::getActorFirst() {
    return MajorActorFirst;
}
string Movie::getActorLast() {
    return MajorActorLast;
}