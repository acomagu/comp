#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int main() {
  int ntree;
  while(cin >> ntree, ntree) {
    int fieldw, fieldh;
    cin >> fieldw >> fieldh;
    vector<vector<bool> > treeField(fieldw, vector<bool>(fieldh, false));
    for(int i = 0; i < ntree; ++i) {
      int x, y;
      cin >> x >> y;
      treeField[x - 1][y - 1] = true;
    }
    // for(auto i = treeField.begin(); i != treeField.end(); ++i) {
    //   for(auto j = (*i).begin(); j != (*i).end(); ++j) cout << *j;
    //   cout << endl;
    // }
    int qw, qh;
    cin >> qw >> qh;
    vector<int> candidits;
    for(int x = 0; x < fieldw - qw + 1; ++x) for(int y = 0; y < fieldh - qh + 1; ++y) {
      vector<int> rows;
      for(int i = x; i < x + qw; ++i) rows.push_back(accumulate(treeField[i].begin() + y, treeField[i].begin() + y + qh, 0));
      candidits.push_back(accumulate(rows.begin(), rows.end(), 0));
      // cout << accumulate(rows.begin(), rows.end(), 0);
    }
    cout << *max_element(candidits.begin(), candidits.end()) << endl;
  }
  return 0;
}
