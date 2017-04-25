#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  map<string, string> commits;
  string name, file;
  while(getline(cin, name, ',') && getline(cin, file)) commits[file] = name;
  int nFile = commits.size();
  map<string, int> nOuts;
  for(auto&& commit : commits) nOuts[commit.second] = 0;
  for(auto&& nOut : nOuts) {
    nOut.second = count_if(begin(commits), end(commits), [nOut](pair<string, string> commit)->bool{
      return commit.second == nOut.first;
    });
  }
  for(auto&& nOut : nOuts) cout << nOut.first << ":" << nOut.second * 100 / nFile << "%" << endl;
  return 0;
}
