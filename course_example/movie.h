#ifndef MOVIE_H
#define MOVIE_H

#include "review.h"

class Movie : public Review {
public:
	Movie();
	Movie(uint i, string t, Genre g, long d, float s);
};

Movie::Movie() 
	: Review() {
}

Movie::Movie(uint i, string t, Genre g, long d, float s) 
	: Review(i, t, g, d, s) {
}

#endif