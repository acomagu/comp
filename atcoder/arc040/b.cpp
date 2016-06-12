#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

int main() {
  int n, r;
  cin >> n >> r;
  // vector<int> unmarkeds;
  unordered_set<int> unmarkeds;
  for(int i = 0; i < n; ++i) {
    char c;
    cin >> c;
    if(c == '.') unmarkeds.insert(i);
  }
  vector<int> points;
  int lastoCount = 0;
  while(!unmarkeds.empty()) {
    int mp;
    points.push_back(mp = *(min_element(unmarkeds.begin(), unmarkeds.end())));
    for(int i = 0; i < r; ++i) (unmarkeds.erase(mp + i) == 0) ? ++lastoCount : lastoCount = 0;
  }
  cout << ((points.empty()) ? 0 : (points.size() + *(points.end() - 1) - lastoCount)) << endl;
  return 0;
}
