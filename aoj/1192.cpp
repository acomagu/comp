#include <iostream>
using namespace std;

int main() {
  int x, y, total1;
  while(cin >> x >> y >> total1, x && y && total1) {
    double rate1, rate2;
    rate1 = (double)(x + 100) * 0.01;
    rate2 = (double)(y + 100) * 0.01;
    int maxTotal2 = 0;
    for(int a = 1; a < total1; ++a) {
      int b;
      b = (int)((total1 - (int)(a * rate1)) / rate1);
      cout << a << ' ' << b << endl;
      if(b > 0) maxTotal2 = max(maxTotal2, (int)(a * rate2) + (int)(b * rate2));
    }
    cout << maxTotal2 << endl;
  }
  return 0;
}
