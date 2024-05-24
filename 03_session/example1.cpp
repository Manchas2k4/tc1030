#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {
  int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  cout << "arr[9] = " << arr[9] << "\n";
  cout << "arr[1000] = " << arr[1000] << "\n";

  vector<int> v(10, 1);

  cout << "v[9] = " << v[9] << "\n";
  cout << "v[1000] = " << v[1000] << "\n";

  return 0;
}
