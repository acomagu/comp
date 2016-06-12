#include <stdio.h>

int main() {
  int m, f, r;
  while(1) {
    scanf("%d%d%d", &m, &f, &r);
    if(m == -1 && f == -1 && r == -1) break;
    printf("%c\n", (
      (m < 0 || f < 0) ? 'F' :
      (m + f >= 80) ? 'A' :
      (m + f >= 65) ? 'B' :
      (m + f >= 50 || (m + f >= 30 && r >= 50)) ? 'C' :
      (m + f >= 30) ? 'D' :
      'F'
    ));
  }
  return 0;
}
