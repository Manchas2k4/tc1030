#ifndef COLLECTION_H
#define COLLECTION_H

#include <iostream>
#include <sstream>
#include <fstream>
#include "utility.h"
#include "video.h"

using namespace std;

class Collection {
private:
	Video* myVideos;
	int count, size;
	
public:
	Collection();
	Collection(int s);
	Collection(const Collection &c);
	~Collection();
	
	bool add(Video v);
	bool loadVideos(string filename);
	bool saveVideos(string filename);
	void displayVideos() const;
};

Collection::Collection() {
}

Collection::Collection(int s) {
};

Collection::Collection(const Collection &c) {
}

Collection::~Collection() {
}

bool Collection::add(Video v) {
}

bool Collection::loadVideos(string filename) {
	int id;
	string title, line, data;
	float score;
	ifstream myFile;
	vector<string> tokens;
	
	myFile.open(filename);
	if (myFile.is_open()) {
		delete [] myVideos;
		
		getline(myFile, line);
		tokens = split(line, ',');
		count = stoi(tokens[0]);
		size = stoi(tokens[1]);
		
		myVideos = new Video[size];
		
		for (int i = 0; i < count; i++) {
			getline(myFile, line);
			tokens = split(line, ',');
			id = stoi(tokens[0]);
			title = tokens[1];
			score = stof(tokens[2]);	
			
			myVideos[i] = Video(id, title, score);
		}
		return true;
	}
	return false;
}

bool Collection::saveVideos(string filename) {
	ofstream myFile;
	
	myFile.open(filename);
	if (myFile.is_open()) {
		myFile << count << "," << size << "\n";
		for (int i = 0; i < count; i++) {
			myFile << myVideos[i].getId() << "," << myVideos[i].getTitle() << "," << myVideos[i].getScore() << "\n";
		}
		myFile.close();
		return true;
	}
	return false;
}

void Collection::displayVideos() const {
	cout << "This is my collection...\n";
	for (int i = 0; i < count; i++) {
		cout << myVideos[i].toString() << "\n";
	}
}
#endif