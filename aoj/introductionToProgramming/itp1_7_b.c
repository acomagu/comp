#include <stdio.h>
#define min(a, b) ((a) > (b) ? (b) : (a))
#define max(a, b) ((a) < (b) ? (b) : (a))

int main() {
  int n, x, answer = 0, an;
  while(1) {
    scanf("%d%d", &n, &x);
    answer = 0;
    if(!n && !x) break;
    for(an = n; x + 3 <= an * 3; --an) {
      answer += max(((min(x - an, an) - 1) - (x - an - min(x - an, an) + 1) + 1) / 2, 0);
    }
    printf("%d\n", answer);
  }
  return 0;
}
