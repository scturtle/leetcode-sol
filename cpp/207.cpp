#include <set>
#include <stack>
#include <vector>
#include <utility>
#include <iostream>
using namespace std;

class Solution {
public:
  bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
    vector<vector<int>> pre(numCourses);
    for(auto &p : prerequisites){
      int i = p.first, j = p.second;
      pre[i].push_back(j);
    }
    bool finished[numCourses], saw[numCourses];
    for(int i=0; i<numCourses; i++)
      finished[i] = saw[i] = /*false;*/ pre[i].size() == 0;

    stack<int> s;
    for(int i=0; i<numCourses; i++){
      if(finished[i]) continue;
      s.push(i);
      while(!s.empty()){
        int u = s.top();
        saw[u] = true;
        bool done = true;
        for(int v : pre[u])
          if(!finished[v]){
            if(saw[v]) return false;
            done = false;
            s.push(v);
          }
        if(done){
          finished[u] = true; s.pop();
        }
      }
    }
    return true;
  }
};

int main(int argc, char *argv[]){
  vector<pair<int,int>> v = {{0,0}};//,{0,2},{1,2}};
  cout << Solution().canFinish(1, v);
}

