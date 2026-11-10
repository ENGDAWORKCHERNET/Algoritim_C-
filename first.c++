
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  if (!(cin >> n))
    return 0;

  vector<int> arr(n);
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }

  sort(arr.begin(), arr.end());

  long long sum = 0;
  for (int x : arr) {
    sum += x;
  }

  cout << "Sorted: ";
  for (int x : arr)
    cout << x << " ";
  cout << "\nSum: " << sum << "\n";
  return 0;
}
