#include <vector>
using namespace std;

class Iterator {
  struct Data;
  Data *data;

public:
  Iterator(const vector<int> &nums);
  Iterator(const Iterator &iter);
  virtual ~Iterator();
  int next();
  bool hasNext() const;
};

class PeekingIterator : public Iterator {
  int peekval;
  bool hasnext;
public:
  PeekingIterator(const vector<int> &nums) : Iterator(nums) {
    // Initialize any member here.
    // **DO NOT** save a copy of nums and manipulate it directly.
    // You should only use the Iterator interface methods.
    hasnext = Iterator::hasNext();
    if(hasnext) peekval = Iterator::next();
  }

  // Returns the next element in the iteration without advancing the iterator.
  int peek() {
    return peekval;
  }

  // hasNext() and next() should behave the same as in the Iterator interface.
  // Override them if needed.
  int next() {
    int val = peekval;
    hasnext = Iterator::hasNext();
    if(hasnext) peekval = Iterator::next();
    return val;
  }

  bool hasNext() const {return hasnext;}
};
