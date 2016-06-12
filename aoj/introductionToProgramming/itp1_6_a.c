#include <stdio.h>

int main() {
  int n, i, ns[100];
  scanf("%d", &n);
  for(i = 0; i < n; ++i) scanf("%d", &ns[i]);
  for(i = n - 1; i >= 0; --i) printf("%d%s", ns[i], (i == 0) ? "\n" : " ");
  return 0;
}
