#include <bits/stdc++.h>
using namespace std;

int main() {
  int a;
  cin >> a;
  cout << (int)((a % 2) ? a / 2 * (a / 2 + 1) : pow(a / 2, 2)) << endl;
  return 0;
}
