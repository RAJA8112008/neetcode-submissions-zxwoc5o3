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

class Codec {
public:

    // Encodes a tree to a single string.
    void preOrder(TreeNode* root,string& ans){
        if(root==NULL){
            ans+="#,";
            return;
        }
        ans+=to_string(root->val)+",";
        preOrder(root->left,ans);
        preOrder(root->right,ans);
    }
    string serialize(TreeNode* root) {
        //preOrder
        string ans="";
        preOrder(root,ans);
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* buildTree(string&st,int &idx){
        if(st[idx]=='#'){
           idx+=2;
            return NULL;
        }
        string temp="";
        while(idx<st.size() && st[idx]!=','){
            temp+=st[idx];
            idx++;
        }
        if(st[idx]==','){
            idx++;
        }
        TreeNode* root=new TreeNode(stoi(temp));
        root->left=buildTree(st,idx);
        root->right=buildTree(st,idx);
        return root;
    }
    TreeNode* deserialize(string data) {
        
        int idx=0;
        TreeNode* root=buildTree(data,idx);
        return root;
     
    }
};
