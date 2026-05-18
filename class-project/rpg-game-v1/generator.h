#ifndef GENERATOR_H
#define GENERATOR_H

#include <random>

class Generator {
public:
    static int randomNumber(int min, int max) {
		if (min > max) {
			std::swap(min, max); // Intercambia los valores de min y max
		}
		
        static std::random_device rd;  
        static std::mt19937 gen(rd()); 
        std::uniform_int_distribution<int> dist(min, max);
        
        return dist(gen);
    }
};

#endif