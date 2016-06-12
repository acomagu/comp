#include <stdio.h>

int main() {
  int h, w, y, x, nums[101][101] = {};
  scanf("%d%d", &h, &w);
  for(y = 0; y < h; ++y) for(x = 0; x < w; ++x) {
    scanf("%d", &nums[y][x]);
    nums[y][w] += nums[y][x];
    nums[h][x] += nums[y][x];
    nums[h][w] += nums[y][x];
  }
  for(y = 0; y <= h; ++y) for(x = 0; x <= w; ++x) printf("%d%s", nums[y][x], (x == w) ? "\n" : " ");
  return 0;
}
