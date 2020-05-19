#include <iostream>
#include <string>
#include "review.h"
#include "episode.h"
#include "movie.h"

using namespace std;

int main(int argc, char* argv[]) {
	Review a;
	Review b(1, "Logan's Run", SCIFI);
	Review c(2, "Scary movie", HORROR);
	Episode d(3, "A long way to heaven", DRAMA, 60, 8, 1);
	Movie e(4, "Metropolis", SCIFI, 120, 9);

	cout << "Review a\n";
	cout << a.toString() << "\n";

	cout << "Review b\n";
	cout << b.toString() << "\n";

	float s;
	cout << "new score: ";
	cin >> s;
	b.setScore(s);

	cout << "Review b\n";
	cout << b.toString() << "\n";

	cout << "Episode d\n";
	cout << d.toString() << "\n";

	cout << "Movie e\n";
	cout << e.toString() << "\n";

	return 0;
}