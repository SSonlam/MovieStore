#ifndef MOVIEFACTORY_H
#define MOVIEFACTORY_H

#include "classic.hpp"
#include "comedy.hpp"
#include "drama.hpp"
#include "movie.h"

#include <iostream>

//----------------------------class MovieFactory.hpp------------------------------

class MovieFactory
{
public:
    MovieFactory() = default;
    virtual ~MovieFactory() = default;

    //Only movies within types in the switch can be made
    Movie *create(char MovieType) {
        switch (MovieType) {
        case 'C': {
            Movies = new Classic();
            break;
        }
        case 'D': {
            Movies = new Drama();
            break;
        }
        case 'F': {
            Movies = new Comedy();
            break;
        }
        default: {
            delete Movies;
            cout << "invalid movie type: " << MovieType << endl;
            return nullptr;
        }
        }
        return Movies->create();
    }

private:
    Movie *Movies;
};
#endif
