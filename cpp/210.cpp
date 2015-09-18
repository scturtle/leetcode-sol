#include <set>
#include <stack>
#include <vector>
#include <utility>
#include <iostream>
using namespace std;

class Solution {
public:
  vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
    vector<vector<int>> pre(numCourses);
    for(auto &p : prerequisites){
      int i = p.first, j = p.second;
      pre[i].push_back(j);
    }
    bool finished[numCourses], saw[numCourses];
    vector<int> order;

    for(int i=0; i<numCourses; i++){
      if(pre[i].size() == 0){
        finished[i] = saw[i] = true;
        order.push_back(i);
      } else
        finished[i] = saw[i] = false;
    }

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
            if(saw[v]) return {};
            done = false;
            s.push(v);
          }
        if(done){
          finished[u] = true; s.pop();
          order.push_back(u);
        }
      }
    }
    return order;
  }
};
