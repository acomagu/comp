#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
  int n, cnt;
  vector<int> nums;
  auto insertionSort = [&nums, &n, &cnt](int d) {
    for(int i = d; i < n; ++i) {
      int top = nums[i];
      int j;
      for(j = i - d; j >= 0 && nums[j] > top; j -= d) {
        nums[j + d] = nums[j];
        ++cnt;
      }
      nums[j + d] = top;
    }
  };
  auto shellSort = [&nums, &n, insertionSort]() {
    int maxid = log(2 * n + 1) / log(3) - 1;
    cout << maxid + 1 << endl;
    for(int id = maxid; id >= 0; --id) {
      unsigned int d = (pow(3, id + 1) - 1) / 2;
      cout << d << (id == 0 ? "\n" : " ");
      insertionSort(d);
    }
  };
  cin >> n;
  nums = vector<int>(n);
  for(int& c: nums) cin >> c;
  cnt = 0;
  shellSort();
  cout << cnt << endl;
  for(auto&& c: nums) cout << c << endl;
  return 0;
}
