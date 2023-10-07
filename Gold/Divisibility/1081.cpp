#include <bits/stdc++.h>
 
using i64 = long long;
 
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n; std::cin >> n;
  constexpr int naxm = 1E6;
  std::vector<int> f(naxm + 5, 0);
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
    ++f[a[i]];
  }
  int ans = 1;
  for (int i = 2; i <= naxm; ++i) {
    int g = 0;
    for (int j = i; j <= naxm; j += i) {
      g += f[j];
    }
    if (g >= 2) {
      ans = i;
    }
  }
  std::cout << ans << "\n";
  return 0;
}
