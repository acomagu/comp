class ListElement;
class ListIterator;
using namespace std;

class List {
  friend ListIterator;
  private:
    shared_ptr<ListElement> firstp, lastp;
  public:
    typedef ListIterator iterator;
    List::iterator begin();
    List::iterator end();
    List();
    int size();
    void push_front(int x);
};
