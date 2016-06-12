#include <stdio.h>
#include <string.h>

int main() {
  char s[101], p[101];
  int ans = 0, is, ip, endip;
  scanf("%s%s", s, p);
  for(is = 0; is < strlen(s) && !ans; ++is, endip = 0) for(ip = 0; ip < strlen(p) && !ans && !endip; ++ip) {
    if(s[(is + ip) % strlen(s)] != p[ip]) {
      endip = 1;
    } else if(ip == strlen(p) - 1) ans = 1;
  }
  printf("%s\n", ans ? "Yes" : "No");
  return 0;
}
