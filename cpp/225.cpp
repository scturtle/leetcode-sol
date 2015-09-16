#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

class Stack {
  queue<int> q1, q2;

public:
  // Push element x onto stack.
  void push(int x) { q1.push(x); }

  // Removes the element on top of the stack.
  void pop() {
    int n = q1.size();
    for (size_t i = 0; i < n - 1; i++) {
      q2.push(q1.front());
      q1.pop();
    }
    q1.pop();
    swap(q1, q2);
  }

  // Get the top element.
  int top() { return q1.back(); }

  // Return whether the stack is empty.
  bool empty() { return q1.empty(); }
};

int main() {
  auto s = Stack();
  s.push(1);
  s.push(2);
  s.push(3);
  cout << s.top() << endl;
  s.pop();
  cout << s.top() << endl;
}
