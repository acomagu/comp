#include <stdio.h>

int main() {
  int nums[4][3][10] = {}, n, i, b, f, r, v, ib, iff, ir;
  scanf("%d", &n);
  for(i = 0; i < n; ++i) {
    scanf("%d%d%d%d", &b, &f, &r, &v);
    nums[b - 1][f - 1][r - 1] += v;
  }
  for(ib = 0; ib < 4; ++ib) {
    for(iff = 0; iff < 3; ++iff, printf("\n")) for(ir = 0; ir < 10; ++ir) printf("%2d", nums[ib][iff][ir]);
    if(ib < 3) {
      for(i = 0; i < 20; ++i) printf("#");
      printf("\n");
    }
  }
  return 0;
}
