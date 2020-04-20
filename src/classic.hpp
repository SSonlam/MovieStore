#ifndef CLASSIC_H
#define CLASSIC_H

//-----------------------------class Classic.hpp------------------------------

using namespace std;

class Classic : public Movie
{
public:
    Movie *create() override { return new Classic(); }

    //assuming correct formatting
    bool read(istream &InputFile) override {
        char DiscardComma;
        InputFile >> DiscardComma >> Stock >> DiscardComma;
        Director = readNextItem(InputFile);
        Title = readNextItem(InputFile);
        InputFile >> MajorActorFirst >> MajorActorLast 
            >> ReleaseMonth >> ReleaseYear;
        return true;
    }

    //operator overload for less than, comedy does releasy year then Actor
    bool operator<(Movie &ComparedMovie) override {
        if (getReleaseYear() < ComparedMovie.getReleaseYear()) {
            return true;
        }
        if (getReleaseYear() == ComparedMovie.getReleaseYear()) {

            if (getReleaseMonth() < ComparedMovie.getReleaseMonth()) {
                return true;
            } 

            if (getReleaseMonth() == ComparedMovie.getReleaseYear()) {

                if (getActorFirst().compare(ComparedMovie.getActorFirst()) < 0) {
                    return true;
                }
                    return false;
            }
            return false;
        }

        return false;
    }

    //getters for private variables
    int getReleaseMonth() override {
        return ReleaseMonth;
    }
    string getActorFirst() override {
        return MajorActorFirst;
    }
    string getActorLast() override {
        return MajorActorLast;
    }

    //cout overload
    ostream &printer(ostream& OutStream) const override {
        OutStream << "Classic: " << Stock << " " << Director << " " 
            << Title << " " << MajorActorFirst << " " 
            << MajorActorLast << " " << ReleaseMonth << " " << ReleaseYear;
        return OutStream;
    }
private:
    string MajorActorFirst;
    string MajorActorLast;
    int ReleaseMonth;
};
#endif