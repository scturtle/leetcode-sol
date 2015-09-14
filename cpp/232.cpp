#include<vector>
#include<algorithm>
using namespace std;

class Queue {
  vector<int> f, r;
  void inline blance(){
    if(f.size() < r.size()){
      reverse(r.begin(), r.end());
      r.insert(r.end(), f.begin(), f.end());
      f = r; r = {};
    }
  }
public:
  // Push element x to the back of queue.
  void push(int x) {
    r.push_back(x);
    blance();
  }

  // Removes the element from in front of queue.
  void pop(void) {
    f.pop_back();
    blance();
  }

  // Get the front element.
  int peek(void) {
    return f[f.size()-1];
  }

  // Return whether the queue is empty.
  bool empty(void) {
    return f.size() == 0;
  }
};
