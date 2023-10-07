#include <bits/stdc++.h>

using i64 = long long;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n; std::cin >> n;
  std::set<int> ans;
  i64 mod = 1;
  for (int i = 1; i < n; ++i) {
    if (std::__gcd(i, n) == 1) {
      ans.insert(i);
      mod *= 1LL * i;
      mod %= n;
    }
  }
  if (mod != 1) {
    assert(ans.count(mod));
    ans.erase(mod);
  }
  std::cout << ans.size() << "\n";
  for (int v : ans) {
    std::cout << v << " \n"[v == *--ans.end()];
  }
  return 0;
}
