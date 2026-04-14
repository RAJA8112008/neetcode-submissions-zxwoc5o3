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
    int findpos(vector<int>&inorder,int st,int ed,int val){
        for(int i=st;i<=ed;i++){
            if(inorder[i]==val){
                return i;
            }
        }
        return -1;
    }
      TreeNode* solve(vector<int>&preorder,vector<int>&inorder,int &preIdx,int st,int ed){
        if (st > ed) return NULL;
        TreeNode* root=new TreeNode(preorder[preIdx++]);
        //getting range 
        int pos=findpos(inorder,st,ed,root->val);
        root->left=solve(preorder,inorder,preIdx,st,pos-1);
        root->right=solve(preorder,inorder,preIdx,pos+1,ed);
        return root;
      }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preIdx=0;
       return solve(preorder,inorder,preIdx,0,inorder.size()-1);
    }
};
