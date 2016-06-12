#include <stdio.h>

int main() {
  int h, w, y, x, matrix[100][100], vector[100], a;
  scanf("%d%d", &h, &w);
  for(y = 0; y < h; ++y) for(x = 0; x < w; ++x) scanf("%d", &matrix[y][x]);
  for(x = 0; x < w; ++x) scanf("%d", &vector[x]);
  for(y = 0; y < h; ++y) {
    a = 0;
    for(x = 0; x < w; ++x) a += matrix[y][x] * vector[x];
    printf("%d\n", a);
  }
  return 0;
}
