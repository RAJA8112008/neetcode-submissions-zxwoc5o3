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
 int getPos(vector<int>&Inorder,int val){
    //find value in order
    for(int i=0;i<Inorder.size();i++){
        if(val==Inorder[i]){
            return i;
        }
    }
    return -1;
 }
   TreeNode*solve(vector<int>&preorder, vector<int>& inorder,int&Indx,int st,int ed){
    if(st>ed)return NULL;
    int element=preorder[Indx++];
    TreeNode* root=new TreeNode(element);
    int pos=getPos(inorder,element);
    root->left=solve(preorder,inorder,Indx,st,pos-1);
    root->right=solve(preorder,inorder,Indx,pos+1,ed);
     return root;
   }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
       
        int Indx=0;
        int n=inorder.size()-1;
       return solve(preorder,inorder,Indx,0,n);
    }
};
