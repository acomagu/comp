#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;
class Card {
  public:
    int number;
    Card(int _number) {
      number = _number;
    }
    int str() {
      return number;
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

vector<Card> SelectionSort(vector<Card>);
vector<Card> BubbleSort(vector<Card>);
string cardsToStr(vector<Card> &);


int main() {
  vector<Card> cards;
  Card card1 = Card(2);
  cards.push_back(card1);
  Card card2 = Card(3);
  cards.push_back(card2);
  swap(cards[0], cards[1]);
  // vector<Card> result1 = BubbleSort(cards);
  // vector<Card> result2 = SelectionSort(cards);
  cout << cardsToStr(cards) << endl;
  return 0;
}

void pResult(vector<Card> &sorted, vector<Card> &original) {
  string s_result = cardsToStr(sorted);
  cout << s_result << endl;
  cout << ((s_result == cardsToStr(original)) ? "Stable" : "Unstable") << endl;
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
    for(int j = cards.size() - 1; j >= 0; --j) {
      if(cards[j] > cards[j - 1]) swap(cards[j], cards[j - 1]);
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

