#ifndef EPISODE_H
#define EPISODE_H

#include "review.h"

class Episode : public Review {
private:
	uint season;

public:
	Episode();
	Episode(uint i, string t, Genre g, long d, float s, uint se);
	Episode(const Episode &obj);
	uint getSeason() const;
	string toString() const;
};

Episode::Episode() 
	: Review(), season(0) {
}

Episode::Episode(uint i, string t, Genre g, long d, float s, uint se) 
	: Review(i, t, g, d, s), season(se) {
}

Episode::Episode(const Episode &obj)
	:Review(obj.id, obj.title, obj.genre, obj.duration, obj.score), season(obj.season) {
}

uint Episode::getSeason() const {
	return season;
}

string Episode::toString() const {
	stringstream aux;

	aux << Review::toString() << " season = " << season;

	return aux.str();
}

#endif