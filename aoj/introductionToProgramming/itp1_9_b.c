#include <stdio.h>
#include <string.h>

int main() {
  char str[201];
  int nh, h, is, iis, ih, len;
  while(scanf("%s", str), strcmp(str, "-")) {
    len = strlen(str);
    scanf("%d", &nh);
    for(is = ih = 0; ih < nh; ++ih) {
      scanf("%d", &h);
      is = (is + h) % len;
    }
    for(iis = 0; iis < len; ++iis) printf("%c", str[(is + iis) % len]);
    printf("\n");
  }
  return 0;
}
