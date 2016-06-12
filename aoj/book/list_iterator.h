class List;
class ListElement;
using namespace std;

class ListIterator : public iterator<bidirectional_iterator_tag, ListElement> {
  private:
    weak_ptr<ListElement> currentp;
    void next();
    void prev();
  public:
    ListIterator(unique_ptr<List> list, bool isLast);
    ListIterator(const ListIterator& right) {}
    int& operator*();
    ListIterator& operator++();
    ListIterator operator++(int);
    ListIterator& operator--();
    ListIterator operator--(int);
    bool operator==(const ListIterator& right);
    bool operator!=(const ListIterator& right);
};
