#include <algorithm>
#include <chrono>
#include <iostream>
#include <random>
#include <vector>

using namespace std;

long long maxSubsequenceSumCubic(const vector<long long> &a) {
  long long maxSum = 0;
  for (size_t i = 0; i < a.size(); ++i) {
    for (size_t j = i; j < a.size(); ++j) {
      long long thisSum = 0;
      for (size_t k = i; k <= j; ++k) {
        thisSum += a[k];
      }
      if (thisSum > maxSum) {
        maxSum = thisSum;
      }
    }
  }
  return maxSum;
}

long long maxSubsequenceSumQuadratic(const vector<long long> &a) {
  long long maxSum = 0;
  for (size_t i = 0; i < a.size(); ++i) {
    long long thisSum = 0;
    for (size_t j = i; j < a.size(); ++j) {
      thisSum += a[j];
      if (thisSum > maxSum) {
        maxSum = thisSum;
      }
    }
  }
  return maxSum;
}

long long maxSubsequenceSumLinear(const vector<long long> &a) {
  long long thisSum = 0;
  long long maxSum = 0;
  for (long long value : a) {
    thisSum += value;
    if (thisSum > maxSum) {
      maxSum = thisSum;
    } else if (thisSum < 0) {
      thisSum = 0;
    }
  }
  return maxSum;
}

// ---- Part (a): random array, ~1/4 negative ----
vector<long long> makeRandomInput(long long n, unsigned seed) {
  mt19937 gen(seed);
  vector<long long> a(static_cast<size_t>(n));

  long long neg = n / 4;
  long long pos = n - neg;

  for (long long i = 0; i < pos; ++i)
    a[static_cast<size_t>(i)] = 1 + gen() % 100;

  for (long long i = 0; i < neg; ++i)
    a[static_cast<size_t>(pos + i)] = -(1 + gen() % 100);

  shuffle(a.begin(), a.end(), gen);
  return a;
}

// ---- timer ----
template <class F> double timeIt(F f, const vector<long long> &a) {
  auto start = chrono::steady_clock::now();
  volatile long long r = f(a);
  auto end = chrono::steady_clock::now();
  (void)r;
  return chrono::duration<double, milli>(end - start).count();
}

int main() {
  long long n;
  if (!(cin >> n) || n < 0) {
    cerr << "Please enter a non-negative sequence length.\n";
    return 1;
  }

  vector<long long> a = makeRandomInput(n, 12345);

  // correctness check — all three must match
  long long r1 = maxSubsequenceSumCubic(a);
  long long r2 = maxSubsequenceSumQuadratic(a);
  long long r3 = maxSubsequenceSumLinear(a);
  cout << "check: " << r1 << " " << r2 << " " << r3
       << (r1 == r2 && r2 == r3 ? "  OK" : "  MISMATCH!") << "\n";

  // timing
  cout << "cubic(ms):  " << timeIt(maxSubsequenceSumCubic, a) << "\n";
  cout << "quad(ms):   " << timeIt(maxSubsequenceSumQuadratic, a) << "\n";
  cout << "linear(ms): " << timeIt(maxSubsequenceSumLinear, a) << "\n";
  return 0;
}
