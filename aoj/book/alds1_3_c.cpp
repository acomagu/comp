#include <iostream>
#include <iterator>
#include <memory>
#include <iterator>
// #include "list.h"
// #include "list_iterator.h"
// #include "list_element.h"
using namespace std;


// Headers

class List {
  private:
  public:
    class ListElement {
      private:
      public:
        int content;
        shared_ptr<ListElement> next, prev;
        ListElement(int x);
        ListElement(const List::ListElement& right);
    };
    shared_ptr<ListElement> firstp, lastp;
    class Iterator : public iterator<bidirectional_iterator_tag, ListElement> {
      private:
        weak_ptr<ListElement> currentp;
        void next();
        void prev();
      public:
        Iterator(unique_ptr<List> list, bool isLast);
        Iterator(const List::Iterator& right);
        int& operator*();
        Iterator& operator++();
        Iterator operator++(int);
        Iterator& operator--();
        Iterator operator--(int);
        bool operator==(const List::Iterator& right);
        bool operator!=(const List::Iterator& right);
    };
    List();
    List(const List& right);
    Iterator begin();
    Iterator end();
    void push_front(int x);
};


// Codes

List::ListElement::ListElement(int x) {
  content = x;
}
List::ListElement::ListElement(const List::ListElement& right) {
  this->next = right.next;
  this->prev = right.prev;
}

List::Iterator List::begin() {
  return *(new List::Iterator(unique_ptr<List>(this), false));
}
List::Iterator List::end() {
  return List::Iterator(unique_ptr<List>(this), true);
}
List::List() {
  firstp = lastp = nullptr;
}
List::List(const List& right) {
  cout << "List Copy Constructor start" << endl;
  this->firstp = right.firstp;
  this->lastp = right.lastp;
}
void List::push_front(int x) {
  if(firstp.get() == nullptr) {
    cout << "push_front: first==null" << endl;
    firstp = lastp = shared_ptr<ListElement>(new ListElement(x));
  } else {
    cout << "push_front: first!=null" << endl;
    auto nep = shared_ptr<ListElement>(new ListElement(x));
    (*firstp).prev = nep;
    firstp = nep;
  }
}

List::Iterator::Iterator(unique_ptr<List> list, bool isLast) {
  cout << "List::Iterator::Iterator start" << endl;
  this->currentp = (isLast ? list->lastp : list->firstp);
  cout << "List::Iterator::Iterator end" << endl;
}
List::Iterator::Iterator(const List::Iterator& right) {
  cout << "List::Iterator Copy Constructor start" << endl;
  this->currentp = right.currentp;
  cout << "List::Iterator Copy Constructor end" << endl;
}
void List::Iterator::next() {
  currentp = ((currentp.expired() || currentp.lock().get() == nullptr) ? nullptr : (*currentp.lock()).next);
}
void List::Iterator::prev() {
  currentp = ((currentp.expired() || currentp.lock().get() == nullptr) ? nullptr : (*currentp.lock()).prev);
}
int& List::Iterator::operator*() {
  static int num;
  if(!currentp.expired() && currentp.lock().get() != nullptr) num = currentp.lock()->content;
  return num;
}
List::Iterator& List::Iterator::operator++() {
  next();
  return *this;
}
List::Iterator List::Iterator::operator++(int) {
  List::Iterator result = *this;
  next();
  return result;
}
List::Iterator& List::Iterator::operator--() {
  prev();
  return *this;
}
List::Iterator List::Iterator::operator--(int) {
  List::Iterator result = *this;
  prev();
  return result;
}
bool List::Iterator::operator==(const List::Iterator& right) {
  return (this->currentp.lock() == right.currentp.lock());
}
bool List::Iterator::operator!=(const List::Iterator& right) {
  return !(*this == right);
}


// Main

int main() {
  List list;
  list.push_front(3);
  auto a = list.begin();
  cout << "SUCCESS" << endl;
  return 0;
}
