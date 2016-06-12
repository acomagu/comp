#include <stdio.h>

int main() {
  char c;
  while(scanf("%c", &c) != -1) printf("%c", c + (
    (c >= 0x61 && c <= 0x7a) ? -0x20 :
    (c >= 0x41 && c <= 0x5a) ? 0x20 :
    0
  ));
  return 0;
}
