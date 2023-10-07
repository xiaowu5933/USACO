#include <bits/stdc++.h>

using i64 = long long;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t; std::cin >> t;
  while (t--) {
    int n; std::cin >> n;
    std::string s; std::cin >> s;
    int d = 0, k = 0;
    std::vector<std::map<int, int>> mp(n + 1);
    int ans = 1;
    for (int i = 0; i < n; ++i) {
      if (s[i] == 'D') {
        ++d;
      } else {
        ++k;
      }
      int g = std::__gcd(k, d);
      assert(g);
      std::cout << ++mp[d / g][k / g] << " \n"[i == n - 1];
    }
  }
  return 0;
}
