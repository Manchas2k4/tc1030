#ifndef REVIEW_H
#define REVIEW_H

#include <string>
#include <sstream>

enum genre {UNDEFINED, ACTION, COMEDY, HORROR, DRAMA, ANIMATION, ROMANTIC, MUSICAL, SCIFI, THRILLER, WAR, WESTERN};

typedef unsigned int uint;
typedef enum genre Genre;

using namespace std;

class Review {
private:
	string genreToString() const;

protected:
	uint id;
	string title;
	Genre genre;
	long duration;
	float score;

public:
	Review();
	Review(uint i, string t, Genre g);
	Review(uint i, string t, Genre g, long d, float s);
	Review(const Review &obj);
	uint getId() const;
	string getTitle() const;
	Genre getGenre() const;
	virtual long getDuration() const;
	float getScore() const;
	void setScore(float s);
	virtual string toString() const;
};

Review::Review() {
	id = 0;
	title = "no name";
	genre = UNDEFINED;
	duration = 0;
	score = 0;
}

Review::Review(uint i, string t, Genre g) {
	id = i;
	title = t;
	genre = g;
	duration = 0;
	score = 0;
}

Review::Review(uint i, string t, Genre g, long d, float s) {
	id = i;
	title = t;
	genre = g;
	duration = d;
	score = s;
} 

Review::Review(const Review &obj) {
	id = obj.id;
	title = obj.title;
	genre = obj.genre;
	duration = obj.duration;
	score = obj.score;
}

uint Review::getId() const {
	return id;
}

string Review::getTitle() const {
	return title;
}

Genre Review::getGenre() const {
	return genre;
}

long Review::getDuration() const {
	return duration;
}

float Review::getScore() const {
	return score;
}

void Review::setScore(float s) {
	score = s;
}

string Review::genreToString() const {
	switch(genre) {
		case ACTION : return "action"; //if (g == ACTION) { return "action"}
		case COMEDY : return "comedy"; // else if (g == COMEDY) { return "comedy" }
		case HORROR : return "horror";
		case DRAMA  : return "drama";
		case ANIMATION : return "animation";
		case ROMANTIC : return "romantic";
		case MUSICAL : return "musical";
		case SCIFI : return "scifi";
		case THRILLER : return "thriller";
		case WAR : return "war";
		case WESTERN : return "western";
		default : return "undefined";
	}
}

string Review::toString() const {
	stringstream aux;

	aux << "Id = " << id << " Title = " << title << " Genre = " << genreToString() << " duration = " << duration << " Score = " << score;

	return aux.str();
}

#endif