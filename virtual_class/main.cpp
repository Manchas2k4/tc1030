#include <iostream>
#include <cstdlib>
#include <ctime>
#include "car.h"
#include "racecar.h"
#include "tunedcar.h"

using namespace std;

int main(int argc, char* argv[]) {
	RaceCar rc("Juan", 15);
	TunedCar tc("Luis", 15);

	srand( time(0) );
	rc.goStartingPoint(); tc.goStartingPoint();
	while(!rc.reachTheEnd() && !tc.reachTheEnd()) {
		rc.move();
		tc.move();
		cout << rc.toString() << "\n";
		cout << tc.toString() << "\n";
	}
	
	return 0;
}

/*
#include <iostream>
#include <string>
#include "package.h"
#include "twoday.h"
#include "overnight.h"

using namespace std;

int main(int argc, char* argv[]) {
	Package p("sender1", "recipient1", 10, 2.35); => 10 * 2.35 = 23.5
	TwoDayPackage t("sender2", "recipient2", 10, 2.35, 14.44); => 23.5 + 14.44
	OvernightPackage o("sender3", "recipient3", 10, 2.35, 5.00); => 23.5 + (10 * 5)
	
	cout << "Cost package p: " << p.calculateCost() << "\n";
	cout << "Cost package t: " << t.calculateCost() << "\n";
	cout << "Cost package o: " << o.calculateCost() << "\n";
	return 0;
}*/