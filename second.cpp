#include <chrono>
#include <iomanip>
#include <iostream>
using namespace std;

//
template <class F> double timeIt(F f) {
  auto start = chrono::steady_clock::now();
  volatile long long r = f();
  auto end = chrono::steady_clock::now();
  (void)r;
  return chrono::duration<double, milli>(end - start).count();
}

long long linearLoop(int n) {
  long long a = 0;
  for (int i = 0; i < n; i++) {
    a++;
  }
  return a;
}

long long quadraticLoop(int n) {
  long long b = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      b++;
    }
  }
  return b;
}

void analizeloops(int n) {
  long long a = 0;
  double linearMs = timeIt([n, &a] {
    a = linearLoop(n);
    return a;
  });
  cout << "linear:" << a << " (" << fixed << setprecision(6) << linearMs
       << " ms)" << endl;

  long long b = 0;
  double quadraticMs = timeIt([n, &b] {
    b = quadraticLoop(n);
    return b;
  });
  cout << "quadratic:" << b << " (" << fixed << setprecision(6) << quadraticMs
       << " ms)" << endl;
}

int main() {
  int n;
  cout << "Enter a value for n: ";
  if (!(cin >> n) || n < 0) {
    cerr << "Please enter a non-negative value.\n";
    return 1;
  }

  analizeloops(n);

  return 0;
}
