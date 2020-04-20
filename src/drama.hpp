#ifndef DRAMA_H
#define DRAMA_H

//-----------------------------class Drama.hpp-------------------------------

class Drama : public Movie
{
public:
    Movie *create() override { return new Drama(); }

    //assumes correct formatting
    bool read(istream &InputStream) override {
        char DiscardComma;
        InputStream >> DiscardComma >> Stock >> DiscardComma;
        Director = readNextItem(InputStream);
        Title = readNextItem(InputStream);
        InputStream >> ReleaseYear;
        return true;
    }

    //overload for less than, drama does by Director then Title
    bool operator<(Movie &ComparedMovie) override {
        if (getDirector().compare(ComparedMovie.getDirector()) < 0) {
            return true;
        }
        if (getDirector().compare(ComparedMovie.getDirector()) == 0) {
            if (getTitle().compare(ComparedMovie.getTitle()) < 0) {
                return true;
            }
            return false;
        }
        return false;
    }

    //cout overload
    ostream &printer(ostream& OutStream) const override {
        OutStream << "Drama: " << Stock << " " << Director << " "
            << Title << " " << ReleaseYear;
        return OutStream;
    }

};
#endif
