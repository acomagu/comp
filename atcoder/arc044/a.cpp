#include <iostream>
#include <vector>
#define int long long
using namespace std;

signed main() {
  int q;
  cin >> q;
  if(q == 1) {
    cout << "Not Prime" << endl;
    return 0;
  }
  if(q == 5 || q == 2 || q == 3) {
    cout << "Prime" << endl;
    return 0;
  }
  if(q % 5 && q % 2 && q % 3) {
    cout << "Prime" << endl;
    return 0;
  }
  // vector<bool> isPrimes(q + 1, true);
  // isPrimes[1] = false;
  // for(int i = 2; i < isPrimes.size(); ++i) {
  //   if(isPrimes[i]) for(int k = 2; i * k < isPrimes.size(); ++k) {
  //     isPrimes[i * k] = false;
  //     if(!isPrimes[q]) {
  //       cout << "Not Prime" << endl;
  //       return 0;
  //     }
  //     cout << i << endl;
  //     if(i > 1000000) {
  //       cout << "Prime" << endl;
  //       return 0;
  //     }
  //   }
  // }
  cout << "Not Prime" << endl;
  return 0;
}
