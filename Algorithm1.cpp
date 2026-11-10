#include <iostream>
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

int main() {
  long long n;
  if (!(cin >> n) || n < 0) {
    cerr << "Please enter a non-negative sequence length.\n";
    return 1;
  }

  vector<long long> a(static_cast<size_t>(n));
  for (long long i = 0; i < n; ++i) {
    a[static_cast<size_t>(i)] = (i % 4 == 0) ? -3 : 2;
  }

  long long r1 = maxSubsequenceSumCubic(a);
  long long r2 = maxSubsequenceSumQuadratic(a);
  long long r3 = maxSubsequenceSumLinear(a);

  cout << "cubic =" << r1 << '\n'
       << "quadratic =" << r2 << '\n'
       << "linear =" << r3 << '\n';
  return 0;
}
