#ifndef MOVIE_H
#define MOVIE_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

//-----------------------------header Movie.h-------------------------------

class Movie
{
    friend ostream &operator<<(ostream &OutStream, const Movie &M) {
        return M.printer(OutStream);
    }

public:
    virtual Movie *create() = 0;
    virtual bool read(istream &InputStream) = 0;
    virtual ostream &printer(ostream& OutStream) const = 0;
    virtual bool operator<(Movie &ComparedMovie) = 0;
    string readNextItem(istream &InputStream, char Delimiter = ',');
    string readNextActor(istream &InputStream, char Delimiter = ' ');
    int getReleaseYear() { return ReleaseYear; }
    virtual int getReleaseMonth() { return 0; }
    virtual string getActorFirst();
    virtual string getActorLast();
    const string discardLine(istream &InputStream);
    string getTitle();
    string getDirector();
    bool stockBorrowed();
    void stockReturned();
    virtual ~Movie() = default;

protected:
    string Director;
    string Title;
    string MajorActorFirst;
    string MajorActorLast;
    int ReleaseYear;
    int ReleaseMonth;
    int Stock;
    vector<string> History;
};
#endif

