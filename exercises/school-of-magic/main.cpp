#include <iostream>
#include <iomanip>
#include <list>
#include "spell.h"

using namespace std;

int main() {
    list<Spell*> grimoire;
    
    // Crear instancias de cada tipo de hechizo
    grimoire.push_back(new AttackSpell(50));
    grimoire.push_back(new DefenseSpell(30));
    grimoire.push_back(new HealingSpell(40));
    
    // Lanzar todos los hechizos
    for (Spell* spell : grimoire) {
        spell->launch();
        cout << spell->toString() << "\n";
    }
    
    // Comparar potencia entre dos hechizos
	Spell *best = grimoire.front();
	for (Spell* s : grimoire) {
		if (*best < *s) {
			best = s;
		}
	}
    cout << "The most powerful spell has a base power " 
		 << best->getPower() << ".\n";
    
	// Limpiar la memoria
    for (Spell* spell : grimoire) {
        delete spell;
    }
    
    return 0;
}