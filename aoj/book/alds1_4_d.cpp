#include <iostream>
#include <functional>
#include <vector>
#define int long long
using namespace std;

signed main() {
  int n, k;
  cin >> n >> k;
  vector<int> ws;
  for(int i = 0; i < n; ++i) {
    int w;
    cin >> w;
    ws.push_back(w);
  }
  function<bool(int)> isLoadable = [&](int p) {
    int iw = 0;
    for(int itrack = 0; itrack < k; ++itrack) {
      int track = 0;
      while(true) {
        track += ws[iw];
        if(track > p) break;
        ++iw;
        if(iw >= n) return true;
      }
    }
    return false;
  };
  int left = 0;
  int right = 100000 * 10000;
  int mid;
  while(right - left > 1) {
    mid = (left + right) / 2;
    (isLoadable(mid) ? right : left) = mid;
  }
  cout << right << endl;
  return 0;
}
