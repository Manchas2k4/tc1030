#include <iostream>
#include <string>
#include "review.h"

using namespace std;


//{UNDEFINED, ACTION, COMEDY, HORROR, DRAMA, ANIMATION, ROMANTIC, MUSICAL, SCIFI, THRILLER, WAR, WESTERN};

void function(Review aux) {
	aux.setScore(100);
	aux.toString();
}

int main(int argc, char* argv[]) {
	Review a;
	Review b(1, "Logan's Run", SCIFI);
	Review c(2, "Scary movie", HORROR);

	cout << "Review a\n";
	a.toString();

	cout << "Review b\n";
	b.toString();

	float s;
	cout << "new score: ";
	cin >> s;
	b.setScore(s);

	cout << "Review b\n";
	b.toString();

	Review d(b);
	cout << "Review d\n";
	d.toString();

	function(b);
	cout << "Review b\n";
	b.toString();

	return 0;
}