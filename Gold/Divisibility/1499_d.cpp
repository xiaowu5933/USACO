#include <bits/stdc++.h>

using i64 = long long;

i64 pow(i64 a, int b) {
  i64 r = 1;
  for (; b; b /= 2, a *= a) {
    if (b & 1) {
      r *= a;
    }
  }
  return r;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  constexpr int naxm = 2E7;
  std::vector<int> lp(naxm + 5, 0);
  std::vector<int> pr;
  for (int i = 2; i <= naxm; ++i) {
    if (!lp[i]) {
      lp[i] = i;
      pr.push_back(i);
    }
    for (int j = 0; 1LL * pr[j] * i <= naxm; ++j) {
      lp[i * pr[j]] = pr[j];
      if (lp[i] == pr[j]) {
        break;
      }
    }
  }
  std::vector<int> cnt(naxm + 5, 0);
  for (int v : pr) {
    for (int i = v; i <= naxm; i += v) {
      ++cnt[i];
    }
  }
  int t; std::cin >> t;
  while (t--) {
    int c, d, x; std::cin >> c >> d >> x;
    i64 ans = 0;
    for (int i = 1; i * i <= x; ++i) {
      if (x % i == 0) {
        auto work = [&](int g, int f) -> void {
          if ((f + d) % c) {
            return;
          }
          int p = (f + d) / c;
          ans += pow(2, cnt[p]);
        };
        work(i, x / i);
        if (i == x / i) {
          continue;
        }
        work(x / i, i);
      }
    }
    std::cout << ans << "\n";
  }
  return 0;
}
