#include <iostream>

using namespace std;

void swap(int &a, int &b) {
  int temp;

  cout << "before a = " << a << " b = " << b << "\n";

  temp = a;
  a = b;
  b = temp;

  cout << "after a = " << a << " b = " << b << "\n";
}

int main(int argc, char* argv[]) {
  int x = 10, y = 20;

  cout << "before x = " << x << " y = " << y << "\n";
  swap(x, y);
  cout << "after x = " << x << " y = " << y << "\n";
  return 0;
}
