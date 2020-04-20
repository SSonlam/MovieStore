#include "command.h"

//-----------------------------class Command.cpp-------------------------------

//logic to read strings with Spaces
string Command::readNextItem(istream &InputStream, char Delimiter) {
    const char Space = ' ';
    string TempString;
    getline(InputStream, TempString, Delimiter);
    if (TempString.empty()) {
        return TempString;
    }
    return TempString.substr(TempString.find_first_not_of(Space),
        TempString.find_last_not_of(Space) + 1);
}

//get rid of an unwanted line
const string Command::discardLine(istream &InputStream) {
    string Discard;
    getline(InputStream, Discard);
    return Discard;
}

//getters for private data
int Command::getClientID() {
    return ClientID;
}
int Command::getReleaseYear() {
    return ReleaseYear;
}
int Command::getReleaseMonth() {
    return ReleaseMonth;
}
string Command::getTitle() {
    return Title;
}
string Command::getActorFirst() {
    return MajorActorFirst;
}
string Command::getActorLast() {
    return MajorActorLast;
}
string Command::getDirector() {
    return Director;
}
char Command::getMovieType() {
    return MovieType;
}