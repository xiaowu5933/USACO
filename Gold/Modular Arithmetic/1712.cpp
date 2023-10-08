#include <bits/stdc++.h>

using i64 = long long;

i64 power(i64 a, i64 b, int MOD) {
  i64 r = 1;
  while (b) {
    if (b & 1) {
      r *= a;
      r %= MOD;
    }
    a *= a;
    a %= MOD;
    b /= 2;
  }
  return r;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  int t;
  std::cin >> t;

  while (t--) {
    int a, b, c;
    std::cin >> a >> b >> c;

    constexpr int MOD = 1E9 + 7;

    std::cout << power(a, power(b, c, MOD - 1), MOD) << "\n";
  }

  return 0;
}
