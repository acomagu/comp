#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;
int exec();

class Line {
  public:
    string line;
    int i, n;
    Line(string _line) {
      line = _line;
      i = 0;
      read();
    }
    int read() {
      stringstream ss;
      ss << line[i];
      ss >> n;
      // n = static_cast<int>(line[i]);
    }
    bool next() {
      ++i;
      if(i == line.size()) return false;
      read();
      return true;
    }
    int get() {
      return n;
    }
};

int main() {
  int n;
  cin >> n;
  for(int i = 0; i < n; ++i) exec();
  return 0;
}

int exec() {
  vector<vector<char> > chars = {{'.', ',', '!', '?', ' '}, {'a', 'b', 'c'}, {'d', 'e', 'f'}, {'g', 'h', 'i'}, {'j', 'k', 'l'}, {'m', 'n', 'o'}, {'p', 'q', 'r', 's'}, {'t', 'u', 'v'}, {'w', 'x', 'y', 'z'}};
  int n, count;
  string line;
  cin >> line;
  Line pattern(line);
  while(true) {
    count = 0;
    while(!(n = pattern.get())) if(!pattern.next()) {
      cout << endl;
      return 0;
    }
    while(pattern.next(), pattern.get()) ++count;
    cout << chars[n - 1][count % (chars[n - 1].size())];
  }
  return 0;
}


