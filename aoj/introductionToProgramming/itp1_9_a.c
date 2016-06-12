#include <stdio.h>

int main() {
  int count = 0;
  char* p;
  char s[101], w[101];
  scanf("%s", s);
  while(scanf("%s", w), strcmp(w, "END_OF_TEXT")) {
    for(p = w; *p; ++p) *p = tolower(*p);
    if(!strcmp(s, w)) ++count;
  }
  printf("%d\n", count);
  return 0;
}
