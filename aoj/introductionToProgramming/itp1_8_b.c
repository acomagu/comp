#include <stdio.h>
#include <string.h>

int main() {
  int is, a;
  char str[1001];
  while(scanf("%s", str), str[0] != '0') {
    a = 0;
    for(is = 0; is < strlen(str); ++is) a += str[is] - '0';
    printf("%d\n", a);
  }
  return 0;
}
