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

  try {
    v[1000] = 10;
  } catch (Exception e) {
    cout << e.what();
  }

  return 0;
}
