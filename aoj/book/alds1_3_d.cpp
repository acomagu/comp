#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<int> hs = {0};
  char c;
  while(cin >> c) {
    char c;
    cin >> c;
    hs.push_back(hs.back() + (c == '/' ? 1 : c == '_' ? 0 : -1));
  }
  cout << endl;
  return 0;
}
