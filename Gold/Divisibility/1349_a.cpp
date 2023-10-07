#include <bits/stdc++.h>

using i64 = long long;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n; std::cin >> n;
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
  }
  constexpr int naxm = 2E5;
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
  std::vector<std::vector<int>> e(naxm + 5);
  std::vector<int> cnt(naxm + 5, 0);
  for (int i = 0; i < n; ++i) {
    int c = a[i];
    std::set<int> div;
    while (c > 1) {
      div.insert(lp[c]);
      ++cnt[lp[c]];
      c /= lp[c];
    }
    for (int v : div) {
      e[v].push_back(cnt[v]);
      cnt[v] = 0;
    }
  }
  i64 ans = 1;
  for (int i = 2; i <= naxm; ++i) {
    if (e[i].empty()) {
      continue;
    }
    std::sort(e[i].begin(), e[i].end());
    if (e[i].size() == n - 1) {
      ans *= 1LL * std::pow(i, e[i][0]);
    } else if (e[i].size() == n) {
      ans *= 1LL * std::pow(i, e[i][1]);
    }
  }
  std::cout << ans << "\n";
  return 0;
}
