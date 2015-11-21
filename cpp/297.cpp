#include <string>
#include <iostream>
#include <sstream>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
  TreeNode* d(istringstream &istr){
    if(istr.peek() == -1 || istr.peek() == ',' || istr.peek() == ')'){
      return nullptr;
    } else {
      int v; istr.get(); istr >> v; istr.get();
      TreeNode *t = new TreeNode(v);
      t->left = d(istr); istr.get();
      t->right = d(istr); istr.get();
      return t;
    }
  }

public:

  // Encodes a tree to a single string.
  string serialize(TreeNode* root) {
    if(root == nullptr)
      return "";
    ostringstream ostr;
    ostr << "(" << root->val << ","
         << serialize(root->left) << ","
         << serialize(root->right) << ")";
    return ostr.str();
  }

  // Decodes your encoded data to tree.
  TreeNode* deserialize(string data) {
    istringstream istr(data);
    return d(istr);
  }
};

int main(){
  Codec codec;
  TreeNode *root = new TreeNode(-1);
  root->left = new TreeNode(0);
  root->right = new TreeNode(1);
  cout << codec.serialize(root) << endl;
  codec.deserialize(codec.serialize(root));
}
