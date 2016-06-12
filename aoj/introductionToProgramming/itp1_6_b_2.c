#include <stdio.h>

int main() {
  int n, cards[52] = {}, i, s, ic;
  char str[1], c;
  scanf("%d", &n);
  for(i = 0; i < n; ++i) {
    scanf("%s%d", str, &s);
    c = str[0];
    ic = 0;
    switch(c) {
      case 'D':
        ic += 13;
      case 'C':
        ic += 13;
      case 'H':
        ic += 13;
    }
    cards[ic + s - 1] = 1;
  }
  for(i = 0; i < 52; ++i) {
    if(!cards[i]) printf("%c %d\n", (char []){'S', 'H', 'C', 'D'}[i / 13], i % 13 + 1);
  }
  return 0;
}
