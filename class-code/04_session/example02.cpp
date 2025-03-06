#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
	int arr[] = {96, 17, 59, 96, 70, 43, 43, 60, 80, 65};

  cout << "arr[2] = " << arr[2] << "\n";
  cout << "*(arr + 2) = " << *(arr + 2) << "\n";

  cout << "*(2 + arr) = " << *(2 + arr) << "\n";
  cout << "2[arr] = " << 2[arr] << "\n"; 

  return 0;
}
