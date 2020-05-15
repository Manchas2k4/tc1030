#include <iostream>
#include <string>
#include "review.h"

using namespace std;


//{UNDEFINED, ACTION, COMEDY, HORROR, DRAMA, ANIMATION, ROMANTIC, MUSICAL, SCIFI, THRILLER, WAR, WESTERN};
string genreToString(Genre g) {
	switch(g) {
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

void function(Review aux) {
	aux.setScore(100);
	cout << "Review aux\n";
	cout << "Id = " << aux.getId() << "\n";
	cout << "Title = " << aux.getTitle() << "\n";
	cout << "Genre = " << genreToString(aux.getGenre()) << "\n";
	cout << "Score = " << aux.getScore() << "\n\n";
}

int main(int argc, char* argv[]) {
	Review a;
	Review b(1, "Logan's Run", SCIFI);
	Review c(2, "Scary movie", HORROR);

	cout << "Review a\n";
	cout << "Id = " << a.getId() << "\n";
	cout << "Title = " << a.getTitle() << "\n";
	cout << "Genre = " << genreToString(a.getGenre()) << "\n";
	cout << "Score = " << a.getScore() << "\n\n";

	cout << "Review b\n";
	cout << "Id = " << b.getId() << "\n";
	cout << "Title = " << b.getTitle() << "\n";
	cout << "Genre = " << genreToString(b.getGenre()) << "\n";
	cout << "Score = " << b.getScore() << "\n\n";

	float s;
	cout << "new score: ";
	cin >> s;
	b.setScore(s);

	cout << "Review b\n";
	cout << "Id = " << b.getId() << "\n";
	cout << "Title = " << b.getTitle() << "\n";
	cout << "Genre = " << genreToString(b.getGenre()) << "\n";
	cout << "Score = " << b.getScore() << "\n\n";

	Review d(b);
	cout << "Review d\n";
	cout << "Id = " << d.getId() << "\n";
	cout << "Title = " << d.getTitle() << "\n";
	cout << "Genre = " << genreToString(d.getGenre()) << "\n";
	cout << "Score = " << d.getScore() << "\n\n";

	function(b);
	cout << "Review b\n";
	cout << "Id = " << b.getId() << "\n";
	cout << "Title = " << b.getTitle() << "\n";
	cout << "Genre = " << genreToString(b.getGenre()) << "\n";
	cout << "Score = " << b.getScore() << "\n\n";

	return 0;
}