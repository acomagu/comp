#include <bits/stdc++.h>
using namespace std;
enum {
  ATT, DEF, SAV
};
class Player {
  public:
    int power;
    int state;
    bool powerflag;
    Player() {
      power = 0;
      powerflag = false;
    }
    void def() {
      if(powerflag) power = 0;
      powerflag = false;
      state = DEF;
    }
    void att() {
      state = ATT;
      if(powerflag) power = 0;
      powerflag = true;
    }
    void sav() {
      state = SAV;
      if(powerflag) power = 0;
      powerflag = false;
      if(power < 5) ++power;
    }
};
int isOvered(Player, Player);

int main() {
  int n;
  cin >> n;
  vector<vector<int>> commands(2);
  for(int t = 1; t >= 0; --t) {
    for(int i = 0; i < n; ++i) {
      string command;
      cin >> command;
      commands[t].push_back(
        command == "kougekida" ? ATT :
        command == "mamoru" ? DEF :
        SAV
      );
    }
  }
  Player nakajima, isono;
  for(int i = 0; i < n; ++i) {
    int t = 0;
    auto operate = [&](Player& player) {
      (
        (commands[t][i] == ATT) ? player.att() :
        (commands[t][i] == DEF) ? player.def() :
        player.sav()
      );
      ++t;
    };
    operate(nakajima);
    operate(isono);
    if(isOvered(nakajima, isono) >= 0) {
      cout << (isOvered(nakajima, isono) ? "Isono-kun" : "Nakajima-kun") << endl;
      return 0;
    }
  }
  cout << "Hikiwake-kun" << endl;
  return 0;
}

int isOvered(Player a, Player b) {
  auto def = [&](int num) {
    return (
      num == ATT ? "ATT" :
      num == DEF ? "DEF" :
      "SAV"
    );
  };
  // cout << def(a.state) << ", " << a.power << ",  " << def(b.state) << ", " << b.power << endl;
  bool t = false;
  do {
    Player me, you;
    (t ? you : me) = a;
    (t ? me : you) = b;
    // cout << "t: " << t << endl;
    if(me.state == ATT && you.state == ATT) {
      if(me.power == you.power) return -1;
      if(me.power > you.power) return t;
    } else if(me.state == ATT && me.power == 0) {
      return !t;
    } else if(me.state == ATT && you.state == DEF) {
      if(me.power == 5) return t;
      return -1;
    } else if(me.state == ATT && you.state == SAV) {
      return t;
    }
  } while(t = !t, t);
  return -1;
}
