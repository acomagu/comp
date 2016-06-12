#include <bits/stdc++.h>
using namespace std;

int main() {
  int li, ri, ln, rn;
  cin >> li >> ri >> ln >> rn;
  auto operate = [&]() {
    if(li >= 5) li = -1;
    if(ri >= 5) ri = -1;
    if(ln >= 5) ln = -1;
    if(rn >= 5) rn = -1;
  };
  auto isOvered = [&]() {
    if((li == -1 && ri == -1) || (ln == -1 && rn == -1)) return true;
    return false;
  };
  while(true) {
    (ln > rn ? ln : rn) += max(li, ri);
    operate();
    cout << li << ' ' << ri << endl << ln << ' ' << rn << endl;
    if(isOvered()) {
      cout << "Isono" << endl;
      return 0;
    }
    (li > ri ? li : ri) += max(ln, rn);
    operate();
    cout << li << ' ' << ri << endl << ln << ' ' << rn << endl;
    if(isOvered()) {
      cout << "Nakajima" << endl;
      return 0;
    }
  }
  return 0;
}
