#include <iostream>
using namespace std;

int main() {
  long long n;
  cout << "Enter a value for n: ";
  if (!(cin >> n)) {
    return 1;
  }

  long long count = 0;

  for (long long i = 0; i < n; ++i) {
    for (long long j = 1; j < n; j *= 2) {
      count++;
    }
  }

  cout << "Iterations: " << count << '\n';
  return 0;
}
