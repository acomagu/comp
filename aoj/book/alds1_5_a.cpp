#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;
bool isYes(int, multiset<int>);
map<pair<int, multiset<int>>, bool> memo;

int main() {
  int na;
  cin >> na;
  multiset<int> as;
  for(int in = 0; in < na; ++in) {
    int a;
    cin >> a;
    as.insert(a);
  }
  int nq;
  cin >> nq;
  for(int iq = 0; iq < nq; ++iq) {
    int q;
    cin >> q;
    cout << (isYes(q, as) ? "yes" : "no") << endl;
    memo.clear();
  }
  return 0;
}

bool isYes(int q, multiset<int> as) {
  if(memo.count(make_pair(q, as))) return memo[make_pair(q, as)];
  bool rtn = false;
  if(q == 0) return true;
  if(q < 0) return false;
  for(auto&& a : as) {
    auto as2 = as;
    as2.erase(as2.find(a));
    if(isYes(q - a, as2)) {
      memo[make_pair(q, as)] = true;
      return true;
    }
  }
  memo[make_pair(q, as)] = false;
  return false;
}
