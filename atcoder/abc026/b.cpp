#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> rs;
  for(int i = 0; i < n; ++i) {
    int r;
    cin >> r;
    rs.push_back(r);
  }
  sort(begin(rs), end(rs));
  reverse(begin(rs), end(rs));
  double s = 0;
  for(int i = 0; i < n; ++i) s += (i % 2) ? -rs[i] * rs[i] : rs[i] * rs[i];
  cout << setprecision(15) << s * 3.141592653589793238462643383279502884 << endl;
  return 0;
}
