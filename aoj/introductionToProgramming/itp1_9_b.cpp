#include <iostream>
using namespace std;

int main() {
  string str;
  while(cin >> str, str != "-") {
    int len = str.size(), is = 0, nh, h;
    cin >> nh;
    for(int ih = 0; ih < nh; ++ih) {
      cin >> h;
      is += h;
    }
    is %= len;
    cout << str.substr(is) << str.substr(0, is) << endl;
  }
  return 0;
}
