#include <iostream>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  int ans = 0;
  for(int i = 0; i < n; ++i) {
    ans += (ans + ans / k) / k;
    ++ans;
  }
  cout << ans - 1<< endl;
  return 0;
}
