#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> diffWaysToCompute(string input) {
    bool alldigit = true;
    int val = 0;
    for (char c : input) {
      if (c < '0' || c > '9') {alldigit = false; break;}
      val = val * 10 + c - '0';
    }
    if (alldigit) return {val};

    vector<int> ans;
    for (size_t i = 0; i < input.size(); i++) {
      if (input[i] == '+' || input[i] == '-' || input[i] == '*') {
        vector<int> lefts = diffWaysToCompute(input.substr(0, i));
        vector<int> rights = diffWaysToCompute(input.substr(i + 1, input.size() - i - 1));
        for (int l : lefts)
          for (int r : rights)
            switch (input[i]) {
            case '+': ans.push_back(l + r); break;
            case '-': ans.push_back(l - r); break;
            case '*': ans.push_back(l * r); break;
            }
      }
    }
    return ans;
  }
};

int main() {
  for (int i : Solution().diffWaysToCompute("15-5"))
    cout << i << " ";
  cout << endl;
}
