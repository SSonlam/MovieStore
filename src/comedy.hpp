#ifndef COMEDY_H
#define COMEDY_H

//-----------------------------class Comedy.hpp-------------------------------

class Comedy : public Movie
{
public:
    Movie *create() override { return new Comedy(); }

    //assumes correct formatting
    bool read(istream &InputStream) override {
        char DiscardComma;
        InputStream >> DiscardComma >> Stock >> DiscardComma;
        Director = readNextItem(InputStream);
        Title = readNextItem(InputStream);
        InputStream >> ReleaseYear;
        return true;
    }

    //operator overload for less than, comedy does Title then Release Year
    bool operator<(Movie &ComparedMovie) override {
        if (getTitle().compare(ComparedMovie.getTitle()) < 0) {
            return true;
        }
        if (getTitle().compare(ComparedMovie.getTitle()) == 0) {
            if (getReleaseYear() < ComparedMovie.getReleaseYear()) {
                return true;
            }
            return false;
        }
        return false;
    }

    //cout overload
    ostream &printer(ostream& OutStream) const override {
        OutStream << "Comedy: " << Stock << " " << Director << " "
            << Title << " " << ReleaseYear;
        return OutStream;
    }
};
#endif
