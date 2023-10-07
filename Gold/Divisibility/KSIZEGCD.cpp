#include <bits/stdc++.h>

using i64 = long long;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t; std::cin >> t;
  while (t--) {
    int n; std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      std::cin >> a[i];
    }
    constexpr int LOG = 20;
    std::vector<std::vector<int>> f(n, std::vector<int> (LOG + 1));
    for (int j = 0; j <= LOG; ++j) {
      for (int i = 0; i + (1 << j) <= n; ++i) {
        f[i][j] = (j == 0 ? a[i] : std::__gcd(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]));
      }
    }
    auto rmq = [&](int l, int r) -> int {
      assert(r > l);
      int k = std::__lg(r - l);
      return std::__gcd(f[l][k], f[r - (1 << k)][k]);
    };
    std::vector<int> ans(n + 1, 1);
    for (int i = 0; i < n; ++i) {
      int j = i;
      while (j < n) {
        int g = rmq(i, j + 1);
        if (g == 1) {
          break;
        }
        int lo = j - 1, hi = n;
        while (hi - lo > 1) {
          int m = (lo + hi) / 2;
          if (rmq(i, m + 1) == g) {
            lo = m;
          } else {
            hi = m;
          }
        }
        ans[lo - i + 1] = std::max(ans[lo - i + 1], g);
        j = lo + 1;
      }
    }
    for (int i = n - 1; i >= 0; --i) {
      ans[i] = std::max(ans[i], ans[i + 1]);
    }
    for (int i = 1; i <= n; ++i) {
      std::cout << ans[i] << " \n"[i == n];
    }
  }
  return 0;
}
