using namespace std;
class ListIterator : public iterator<bidirectional_iterator_tag, ListElement> {
  private:
    weak_ptr<ListElement> currentp;
    ListIterator(unique_ptr<List> list, bool isLast) {
      currentp = (isLast ? list->lastp : list->firstp);
    }
    void next() {
      currentp = ((currentp == nullptr) ? nullptr : (*currentp).next);
    }
    void prev() {
      currentp = ((currentp == nullptr) ? nullptr : (*currentp).prev);
    }
  public:
    ListIterator(const ListIterator& right) {}
    int& operator*() {
      static int num;
      if(currentp != nullptr) num = currentp->content;
      return num;
    }
    ListIterator& operator++() {
      next();
      return *this;
    }
    ListIterator operator++(int) {
      ListIterator result = *this;
      next();
      return result;
    }
    ListIterator& operator--() {
      prev();
      return *this;
    }
    ListIterator operator--(int) {
      ListIterator result = *this;
      prev();
      return result;
    }
    bool operator==(const ListIterator& right) {
      return (this->currentp == right.currentp);
    }
    bool operator!=(const ListIterator& right) {
      return !(*this == right);
    }
};
