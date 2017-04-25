#include <iostream>
using namespace std;

int main() {
  int n;
  while(cin >> n) {
    int res = 0;
    for(int k = 0; n * k < 2000000; ++k) {
      int sum = n * k;
      if(sum % 2 && (sum + 1) / 2 <= 1000000) {
        res++;
      }
    }
    cout << res << endl;
  }
  return 0;
}
