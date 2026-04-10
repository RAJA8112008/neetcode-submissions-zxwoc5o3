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
  TreeNode* solve(TreeNode* root, TreeNode* p,TreeNode* q){
    if(!root)return NULL;
 if((root->val==p->val)||(root->val==q->val))return root;
   
  //case 1:both are in diffre sides
   TreeNode* leftside=solve(root->left,p,q);
    TreeNode* rightside=solve(root->right,p,q); 
   if(leftside && rightside)return root;
   if(leftside && !rightside)return leftside;
   if(!leftside && rightside)return rightside;
    return NULL;
  }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return solve(root,p,q);
    }
};
