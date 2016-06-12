#include <iostream>
#include <vector>
#include <unordered_multiset>
#include <algorithm>
#include <deque>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> hs;
  unordered_multiset<int> ws;
  for(int i = 0; i < n; ++i) {
    int h;
    cin >> h;
    hs.push_back(h);
  }
  for(int i = 0; i < m; ++i) {
    int w;
    cin >> w;
    ws.insert(w);
  }
  deque<bool> selection(n, false);
  selection[n - 1] = selection[n - 2] = true;
  auto findCombination = [&](int w, unordered_multiset<int> wws) {
    int res = wws.count(w);
    if(res) {
      return res;
    } else if(w > 1) {
      for(int ww = w - 1; ww >= w / 2; --w) {
        auto wws1 = wws;
        auto wws2 = wws;
        findCombination(ww, 

  do {
    auto firstit = find(selection.begin(), selection.end(), true);
    cout << hs[firstit - selection.begin()] << endl;
    cout << hs[find(firstit + 1, selection.end(), true) - selection.begin()] << endl;
  } while(next_permutation(selection.begin(), selection.end()));
  return 0;
}
