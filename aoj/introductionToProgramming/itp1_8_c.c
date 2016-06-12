#include <stdio.h>
#include <string.h>

int main() {
  int is, in, nals[26] = {};
  char str[1200];
  while(fgets(str, sizeof(str), stdin) != NULL) {
    for(is = 0; is < strlen(str); ++is) {
      in = str[is] - ((str[is] >= 'a') ? 'a' : 'A');
      if(in >= 0 && in < 26) ++nals[in];
    }
  }
  for(in = 0; in < 26; ++in) printf("%c : %d\n", 'a' + in, nals[in]);
  return 0;
}
