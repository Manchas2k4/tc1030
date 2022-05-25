#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main(int argc, char* argv[]) {
  ifstream inputFile;
  ofstream outputFile;
  int n;
  string id;
  string project[2] = {"comms", "ships"};

  if (argc != 3) {
    cout << "usage: " << argv[0] << " input_file output_file\n";
    return -1;
  }

  inputFile.open(argv[1]);
  if (!inputFile.is_open()) {
    cout << argv[0] << ": File \"" << argv[1] << "\" not found\n";
    return -1;
  }

  outputFile.open(argv[2]);

  srand(time(0));

  inputFile >> n;
  for (int i = 0; i < n; i++) {
    inputFile >> id;
    outputFile << id << "," << project[rand() % 2] << "\n";
  }

  inputFile.close();
  outputFile.close();
  return 0;
}
