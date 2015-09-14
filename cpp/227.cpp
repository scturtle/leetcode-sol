#include <vector>
#include <iostream>
#include <sstream>
using namespace std;

template <typename T> void output(vector<T> &v) {
  cout << "{";
  for (size_t i = 0; i < v.size(); i++) {
    cout << v[i] << (i == v.size() ? "" : ", ");
  }
  cout << "}";
}

class Solution {
  int oper(char op, int a, int b) {
    switch (op) {
    case '+': return a + b;
    case '-': return a - b;
    case '*': return a * b;
    case '/': return a / b;
    }
  }

public:
  int calculate(string s) {
    istringstream ss{s};
    vector<char> ops;
    vector<int> vals;
    int v; char op;
    ss >> v; vals.push_back(v);
    while (ss >> op) {
      ops.push_back(op);
      ss >> v; vals.push_back(v);
    }
    vector<char> ops2;
    vector<int> vals2{vals[0]};
    for (size_t i = 0; i < ops.size(); i++) {
      if (ops[i] == '+' || ops[i] == '-') {
        ops2.push_back(ops[i]);
        vals2.push_back(vals[i + 1]);
      } else {
        int a = vals2.back();
        vals2.pop_back();
        vals2.push_back(oper(ops[i], a, vals[i + 1]));
      }
    }
    int ans = vals2[0];
    for (size_t i = 0; i < ops2.size(); i++) {
      ans = oper(ops2[i], ans, vals2[i + 1]);
    }
    return ans;
  }
};

int main() {
  cout << Solution().calculate(" 3+5 / 2 ");

}
