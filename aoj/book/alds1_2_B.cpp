#include <iostream>
#include <algorithm>
#include <list>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> nums;
  for(int i = 0; i < n; ++i) {
    int num;
    cin >> num;
    nums.push_back(num);
  }
  int count = 0;
  for(int i = 0; i < nums.size(); ++i) {
    auto max = min_element(nums.begin() + i, nums.end());
    if(nums[i] != *max) {
      swap(nums[i], *max);
      ++count;
    }
  }
  for(auto j = nums.begin(); j != nums.end() - 1; ++j) cout << *j << " ";
  cout << *(nums.end() - 1) << endl;
  cout << count << endl;
  return 0;
}

