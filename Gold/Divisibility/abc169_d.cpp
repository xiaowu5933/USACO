#include <bits/stdc++.h>

using i64 = long long;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  i64 n; std::cin >> n;
  std::vector<i64> a;
  i64 _n = n;
  for (int i = 2; 1LL * i * i <= n; ++i) {
    while (_n % i == 0) {
      _n /= i;
      a.push_back(i);
    }
  }
  if (_n > 1) {
    a.push_back(_n);
  }
  std::sort(a.begin(), a.end());
  int ans = 0;
  for (int i = 0; i < int(a.size()); ++i) {
    int j = i;
    while (j < int(a.size()) && a[j] == a[i]) {
      ++j;
    }
    int add = std::sqrt(j - i);
    while (add * (add + 1) / 2 < j - i) {
      ++add;
    }
    while (add * (add + 1) / 2 > j - i) {
      --add;
    }
    ans += add;
    i = j - 1;
  }
  std::cout << ans << "\n";
  return 0;
}
