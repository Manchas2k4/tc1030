#include <iostream>
#include "vector.h"

using namespace std;

int main(int argc, char* argv[]) {
  int n;
  IntegersVector v(20, 1);

  for (int i = 0; i < v.length(); i++) {
    cout << v[i] << " ";
  }
  cout << "\n";

  return 0;
}
