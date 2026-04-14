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
   int solve(TreeNode* root,int& maxSum){
    if(!root)return 0;
    int left=max(0,solve(root->left,maxSum));
    int right=max(0,solve(root->right,maxSum));
    int pathSum=left+right+root->val;
    maxSum=max(maxSum,pathSum);
    return max(left,right)+root->val;
   }
    int maxPathSum(TreeNode* root) {
      if(!root)return 0;
      int maxSum=INT_MIN;
      solve(root,maxSum);
      return maxSum;
    }
};
