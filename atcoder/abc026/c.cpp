#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main() {
  int n;
  cin >> n;
  unordered_map<int, vector<int> > downs(20, vector<int>(0)); // zero base
  for(i = 1; i < n; ++i) {
    int upno;
    cin >> upno;
    downs[upno - 1].push_back(i);
  }
  cout << maxs(downs[0]) + mins(downs[0]) + 1 << endl;
  return 0;
}

int maxs(vector<int> ds) {
  vector<int> points;
  for(auto&& d: ds) points.push_back(maxs(ds[d]));
  return (*max_element(begin(points), end(points))) + 1;
}
int mins(vector<int> ds) {
  vector<int> points;
  for(auto&& d: ds) points.push_back(maxs(ds[d]));
  return (*min_element(begin(points), end(points))) + 1;
}
