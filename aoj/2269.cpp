#include <iostream>
#include <map>
#include <set>
using namespace std;

int main() {
  map<set<int>, int> distances;
  int nPoint, nSide;
  cin >> nPoint >> nSide;
  for(int iSide = 0; iSide < nSide; ++iSide) {
    int iPoint1, iPoint2, distance;
    cin >> iPoint1 >> iPoint2 >> distance;
    distances[set<int>({iPoint1, iPoint2})] = 1;
  }
}
