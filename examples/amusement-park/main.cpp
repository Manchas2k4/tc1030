#include <iostream>
#include <vector>
#include "attraction.h"

using namespace std;

int main(int argc, char* argv[]) {
	vector<Attraction *> park;

	park.push_back(new RollerCoaster(1, "Tornado de Emociones", 15));
	park.push_back(new HouseOfHorror(2, "Cueva del Pánico", 22));
	park.push_back(new BumperCars(3, "Zona de Impacto", 18));
	park.push_back(new RollerCoaster(4, "Carrusel Encantado", 11));
	park.push_back(new HouseOfHorror(5, "Montaña Espacial", 20));
	park.push_back(new BumperCars(6, "Derby de Demolición", 20));
	park.push_back(new RollerCoaster(7, "Tobogán de Aventura", 14));
	park.push_back(new HouseOfHorror(8, "Safari de la Selva", 24));
	park.push_back(new BumperCars(9, "Impacto Frenético", 17));

	cout << "park = " << park.size() << "\n";
	for (Attraction *a : park) {
		cout << (*a) << "\n";
	}

	for (Attraction *a : park) {
		cout << "Diversión generada por " << a->getName() 
			 << " = " << a->calculateFun() << "\n";
	}

	Attraction *best = park[0];
	for (Attraction *a : park) {
		if ((*best) < (*a)) {
			best = a;
		}
	}
	
	cout << "La atracción más divertida es " 
		 << best->getName() << "\n";

	for (Attraction *a : park) {
		delete a;
	}
	return 0;
}