/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
bool solve(TreeNode* node1,TreeNode* node2){
  //if both nodes absent
  if(node1==NULL && node2==NULL)return true;
  //if one is present or sec  is absent
  if((node1==NULL && node2!=NULL)||(node1!=NULL && node2==NULL))return false;
   //if nodes have different valuels
  if(node1->val!=node2->val)return false;
  //check left side

  bool leftcheck=solve(node1->left,node2->left);
  //check right side
  bool rightcheck=solve(node1->right,node2->right);
  return leftcheck && rightcheck;
}
    bool isSameTree(TreeNode* p, TreeNode* q) {
        
       return solve(p,q);
    }
};
