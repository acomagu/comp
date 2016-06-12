#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;
class Card {
  public:
    char type;
    int number;
    Card(char _type, int _number) {
      type = _type;
      number = _number;
    }
    // Card(const Card &original) { // Copy Constractor
      // type = new char[1];
      // type = original.type;
      // number = new int[1];
      // number = original.number;
    // }
    string str() {
      stringstream ss;
      ss << type << number;
      // cout << ss.str() << endl;
      // return ss.str();
      return ss.str();
    }
    bool operator > (const Card &right) {
      return (number > right.number);
    }
    bool operator < (const Card &right) {
      return (number < right.number);
    }
    bool operator >= (const Card &right) {
      return (number >= right.number);
    }
    bool operator <= (const Card &right) {
      return (number <= right.number);
    }
    bool operator == (const Card &right) {
      return (number == right.number);
    }
    bool operator != (const Card &right) {
      return (number != right.number);
    }
};

void pResult(vector<Card> &, vector<Card> &);
vector<Card> BubbleSort(vector<Card>);
vector<Card> SelectionSort(vector<Card>);
string cardsToStr(vector<Card> &);


int main() {
  int n;
  cin >> n;
  vector<Card> cards;
  for(int i = 0; i < n; ++i) {
    string s_card;
    cin >> s_card;
    char c_card;
    int d_card;
    stringstream ss;
    ss << s_card;
    ss >> c_card;
    ss >> d_card;
    Card card(c_card, d_card);
    cards.push_back(card);
  }
  vector<Card> result1 = BubbleSort(cards);
  vector<Card> result2 = SelectionSort(cards);
  pResult(result1, result1);
  pResult(result2, result1);
  return 0;
}

void pResult(vector<Card> &sorted, vector<Card> &original) {
  string s_result = cardsToStr(sorted);
  cout << s_result << endl;
  cout << ((s_result == cardsToStr(original)) ? "Stable" : "Not stable") << endl;
}

string cardsToStr(vector<Card> &cards) {
  stringstream result;
  for(auto i = cards.begin(); i != cards.end(); ++i) {
    result << (*i).str();
    // cout << (*i).str() << endl;
    // cout << cards[0].str() << endl;
    if(i != cards.end() - 1) result << ' ';
  }
  return result.str();
}

vector<Card> BubbleSort(vector<Card> cards) {
  // result.resize(cards.size());
  // copy(cards.begin(), cards.end(), result.begin());
  for(int i = 0; i < cards.size(); ++i) {
    for(int j = cards.size() - 1; j > 0; --j) {
      if(cards[j] < cards[j - 1]) swap(cards[j], cards[j - 1]);
    }
  }
  return move(cards);
}

vector<Card> SelectionSort(vector<Card> cards) {
  for(auto i = cards.begin(); i != cards.end(); ++i) {
    auto itr_min = min_element(i, cards.end());
    iter_swap(i, itr_min);
  }
  return move(cards);
}

