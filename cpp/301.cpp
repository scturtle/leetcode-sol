#include <vector>
#include <unordered_set>
#include <queue>
#include <string>
using namespace std;

class Solution {
  bool isValid(string s){
    int cnt = 0;
    for(char c : s)
      if(c == '(') cnt++;
      else if(c == ')'){
        if(cnt == 0) return false;
        cnt--;
      }
    return cnt == 0;
  }
public:
  vector<string> removeInvalidParentheses(string s) {
    unordered_set<string> saw;
    vector<string> ans;
    bool found = false;
    queue<string> q;
    q.push(s);
    while(!q.empty()){
      s = q.front(); q.pop();
      if(isValid(s)){
        ans.push_back(s);
        found = true;
      }
      if(found) continue;
      for(int i=0; i<s.size(); i++){
        if(s[i] != '(' && s[i] != ')')
          continue;
        string ss = s.substr(0, i) + s.substr(i+1);
        if(saw.find(ss) == saw.end()){
          saw.insert(ss);
          q.push(ss);
        }
      }
    }
    return ans;
  }
};
