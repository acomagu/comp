#include <bits/stdc++.h>
using namespace std;
void rm(vector<deque<char> > &, int, int);

int main() {
  int h, w, n;
  cin >> h >> w >> n;
  vector<deque<char> > origField(w, deque<char>(h)); // [x][-y]
  for(int y = h - 1; y >= 0; --y) for(int x = 0; x < w; ++x) {
    char c;
    cin >> c;
    origField[x][y] = c;
  }
  for(int sx = 0; sx < w - 1; ++sx) for(int sy = 0; sy < h; ++sy) {
    auto field = origField;
    swap(field[sx][sy], field[sx + 1][sy]);
    for(int x = sx; x <= sx + 1; ++x) for(int y = h - 1; y >= 0; --y) if(field[x][y] == '.') rm(field, x, y);
    int removeCnt, lastRemoveCnt;
    removeCnt = lastRemoveCnt = 0;
    do {
      lastRemoveCnt = removeCnt;
      removeCnt = 0;
      vector<vector<int*> > pxfield(w, vector<int*>(h));
      vector<vector<int*> > pyfield(w, vector<int*>(h));
      for(int x = 0; x < w; ++x) for(int y = 0; y < h; ++y) {
        pxfield[x][y] = ((y >= 1 && field[x][y] == field[x][y - 1]) ? pxfield[x][y - 1] : (new int(0)));
        ++(*pxfield[x][y]);
      }
      for(int y = 0; y < h; ++y) for(int x = 0; x < w; ++x) {
        pyfield[x][y] = ((x >= 1 && field[x][y] == field[x - 1][y]) ? pyfield[x - 1][y] : (new int(0)));
        ++(*pyfield[x][y]);
      }
      for(int x = 0; x < w; ++x) for(int y = h - 1; y >= 0; --y) if(max(*pxfield[x][y], *pyfield[x][y]) >= n) {
        rm(field, x, y);
        ++removeCnt;
      }
      if(removeCnt == w * h) {
        cout << "YES" << endl;
        return 0;
      }
    } while(lastRemoveCnt != removeCnt);
  }
  cout << "NO" << endl;
  return 0;
}
void rm(vector<deque<char> > &field, int x, int y) {
  field[x].erase(field[x].begin() + y);
  field[x].push_back('.');
}
