#include <bits/stdc++.h>

using i64 = long long;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n, k; std::cin >> n >> k;
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
  }
  constexpr int naxm = 1E5;
  std::vector<int> lp(naxm + 5, 0);
  std::vector<int> pr;
  for (int i = 2; i <= naxm; ++i) {
    if (!lp[i]) {
      lp[i] = i;
      pr.push_back(i);
    }
    for (int j = 0; 1LL * pr[j] * i <= naxm; ++j) {
      lp[pr[j] * i] = pr[j];
      if (lp[i] == pr[j]) {
        break;
      }
    }
  }
  std::map<std::vector<int>, std::map<std::vector<int>, int>> mp;
  std::vector<int> cnt(naxm + 5, 0);
  i64 ans = 0;
  for (int i = 0; i < n; ++i) {
    int c = a[i];
    std::set<int> div;
    while (lp[c] > 1) {
      div.insert(lp[c]);
      ++cnt[lp[c]];
      c /= lp[c];
    }
    std::vector<int> fx, fy, fz;
    for (int v : div) {
      cnt[v] %= k;
      if (cnt[v]) {
        fx.push_back(v);
        fy.push_back(cnt[v]);
        fz.push_back(k - cnt[v]);
        cnt[v] = 0;
      }
    }
    ans += mp[fx][fz];
    ++mp[fx][fy];
  }
  std::cout << ans << "\n";
  return 0;
}
