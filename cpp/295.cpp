#include <queue>
#include <vector>
#include <iostream>
using namespace std;

class MedianFinder {
  priority_queue<int, std::vector<int>, greater<int>> more;
  priority_queue<int> less;
  int mn=0, ln=0;
public:
  void addNum(int num) {
    if(more.size() == 0 || num > more.top())
      more.push(num);
    else
      less.push(num);
    if(int(more.size()) - int(less.size()) > 1){
      less.push(more.top()); more.pop();
    }else if(int(less.size()) - int(more.size()) > 1){
      more.push(less.top()); less.pop();
    }
  }

  double findMedian() {
    if(more.size() == less.size())
      return (more.top() + less.top()) / 2.0;
    else if(more.size() > less.size())
      return more.top();
    else
      return less.top();
  }
};

int main(){
  auto mf = MedianFinder();
  mf.addNum(1);
  mf.addNum(2);
  mf.addNum(3);
  cout << mf.findMedian() << endl;
}
