#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <utility>
#include <map>
#include <set>
#include <string>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <climits>
#include <numeric>
using namespace std;

template<typename T>
void prints(vector<T> &v){
  cout << "[";
  for(uint i=0; i<v.size()-1; ++i)
    cout << v[i] << ", ";
  if(v.size()) cout << v[v.size()-1];
  cout << "]\n";
}

class DoubleLinkedNode {
public:
  int key, val;
  DoubleLinkedNode *prev;
  DoubleLinkedNode *next;
  DoubleLinkedNode(int key=0, int val=0,
    DoubleLinkedNode *prev=nullptr, DoubleLinkedNode *next=nullptr)
    :key(key),val(val),prev(prev),next(next){}
};

class LRUCache{
  DoubleLinkedNode head, tail;
  int capacity, count;
  unordered_map<int,DoubleLinkedNode*> dict;

public:
  LRUCache(int cap) {
    tail.prev = tail.next = &head;
    head.prev = head.next = &tail;
    capacity = cap;
    count = 0;
  }

  DoubleLinkedNode* delete_node(DoubleLinkedNode* node){
    DoubleLinkedNode *prev = node->prev, *next = node->next;
    prev->next = next;
    next->prev = prev;
    return node;
  }

  void insert_after(DoubleLinkedNode *node, DoubleLinkedNode* prev){
    DoubleLinkedNode *next = prev->next;
    node->prev = prev;
    node->next = next;
    prev->next = next->prev = node;
  }

  int get(int key) {
    if(dict.find(key) != dict.end()){
      DoubleLinkedNode *node = delete_node(dict[key]);
      insert_after(node, &head);
      return node->val;
    }
    return -1;
  }

  void set(int key, int value) {
    if(dict.find(key) != dict.end()){
      DoubleLinkedNode *node = delete_node(dict[key]);
      node->val = value;
      insert_after(node, &head);
    } else {
      if(count == capacity){
        DoubleLinkedNode *to_be_deleted = delete_node(tail.prev);
        dict.erase(to_be_deleted->key);
        delete to_be_deleted;
        --count;
      }
      DoubleLinkedNode *node = new DoubleLinkedNode(key, value);
      insert_after(node, &head);
      dict[key] = node;
      ++count;
    }
  }
};

int main(){
  // auto sol = Solution();
}
