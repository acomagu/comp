#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<bool> primes(123456 * 2 + 1, true); // one based
  primes[1] = false;
  vector<int> primeSums(123456 * 2 + 1, 0);
  for(int n = 2; n < primes.size() / 2; ++n) if(primes[n]) for(int k = 2; k * n < primes.size(); ++k) primes[n * k] = false;
  for(int i = 1; i < primes.size(); ++i) primeSums[i] = primeSums[i - 1] + primes[i];
  int n;
  while(cin >> n, n) cout << primeSums[n * 2] - primeSums[n] << endl;
  return 0;
}
