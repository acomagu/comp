
class List {
  friend ListIterator;
  private:
    shared_ptr<ListElement> firstp, lastp;
  public:
    typedef ListIterator iterator;
    List::iterator begin() {
      return List::iterator(unique_ptr<List>(this), false);
    }
    List::iterator end() {
      return List::iterator(unique_ptr<List>(this), true);
    }
    List() {
      firstp = lastp = nullptr;
    }
    int size() {}
    void push_front(int x) {
      if(firstp == nullptr) {
        firstp = lastp = shared_ptr<ListElement>(new ListElement(x));
      } else {
        auto nep = shared_ptr<ListElement>(new ListElement(x));
        *firstp.prev = nep;
        firstp = nep;
      }
    }
};
