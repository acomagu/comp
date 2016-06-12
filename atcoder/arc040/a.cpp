#include <iostream>
#include <map>
using namespace std;

int main() {
  int xy;
  cin >> xy;
  map<char, int> table;
  for(int i = 0; i < xy * xy; ++i) {
    char c;
    cin >> c;
    (table.find(c) == table.end()) ? table[c] = 1 : ++table[c];
  }
  cout << (
      (table['R'] == table['B']) ? ("DRAW") :
      (table['R'] > table['B']) ? ("TAKAHASHI") :
      ("AOKI")
  ) << endl;
  return 0;
}
