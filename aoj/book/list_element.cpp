int content;
  public:
    shared_ptr<ListElement> next, prev;
    ListElement(int x) {
      content = x;
    }
};
