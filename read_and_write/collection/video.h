#ifndef VIDEO_H
#define VIDEO_H

#include <iostream>
#include <sstream>

using namespace std;

class Video {
private:
	int id;
	string title;
	float score;
	
public:
	Video();
	Video(int i, string t, float s);
	Video(const Video &v);
	int getId() const;
	void setId(int i);
	string getTitle() const;
	void setTitle(string t);
	float getScore() const;
	void setScore(float s);
	string toString() const;
};

Video::Video() {
	id = 0;
	title = "";
	score = 0.0;
}

Video::Video(int i, string t, float s) {
	id = i;
	title = t;
	score = s;
}

Video::Video(const Video &v) {
	id = v.id;
	title = v.title;
	score = v.score;
}

int Video::getId() const {
	return id;
}

void Video::setId(int i) {
	id = i;
}

string Video::getTitle() const {
	return title;
}

void Video::setTitle(string t) {
	title = t;
}

float Video::getScore() const {
	return score;
}

void Video::setScore(float s) {
	score = s;
}

string Video::toString() const {
	stringstream outpout;

	outpout << "Title: " << title << "\nScore = " << score << "\n";
	return outpout.str();
}

#endif