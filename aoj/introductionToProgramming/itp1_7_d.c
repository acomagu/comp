#include <stdio.h>
#define int long long

signed main() {
  int n, m, l, y, x, ns1[100][100], ns2[100][100], im, a;
  scanf("%lld%lld%lld", &n, &m, &l);
  for(y = 0; y < n; ++y) for(x = 0; x < m; ++x) scanf("%lld", &ns1[y][x]);
  for(y = 0; y < m; ++y) for(x = 0; x < l; ++x) scanf("%lld", &ns2[y][x]);
  for(y = 0; y < n; ++y) for(x = 0; x < l; ++x) {
    a = 0;
    for(im = 0; im < m; ++im) a += ns1[y][im] * ns2[im][x];
    printf("%lld%s", a, (x == l - 1 ? "\n" : " "));
  }
  return 0;
}
