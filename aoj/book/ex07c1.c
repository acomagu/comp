#include <stdio.h>

int main() {
  int n, min, max;
  int ns[10];
  puts("10個の整数を空白で区切って入力してください。");
  for(i = 0; i < 10; ++i) scanf("%d", &ns[i]);
  for(min = max = ns[0], i = 0; i < 10; ++i) {
    min = min(min, ns[i]);
    max = max(max, ns[i]);
  }
  printf("最大値は%dです。", max);
  printf("最小値は%dです。", min);
  puts("入力された整数の表示:");
  for(i = 0; i < 10; ++i) {
    if(i != 0) printf(" ");
    printf("%d", ns[i]);
  }
  printf("\n");
  return 0;
}
