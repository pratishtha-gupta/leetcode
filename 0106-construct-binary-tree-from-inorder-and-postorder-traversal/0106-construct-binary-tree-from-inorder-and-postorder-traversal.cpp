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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
       unordered_map<int,int> mp;
       for(int i=0;i<inorder.size();i++)
       {
           mp[inorder[i]]=i;
       } 
       return build(postorder,0,postorder.size()-1,inorder,0,inorder.size()-1,mp);
    }
    TreeNode* build(vector<int>&postorder,int poststart,int postend,vector<int>&inorder,int instart,int inend, unordered_map<int,int> &mp)
    {
        if(poststart>postend||instart>inend) return nullptr;
        int rootval = postorder[postend];
        TreeNode* root = new TreeNode (rootval);
        int rootindex = mp[rootval];
        int leftsize = rootindex-instart;
        root->left = build(postorder, poststart, poststart + leftsize - 1,
                           inorder, instart, rootindex - 1, mp);

        root->right = build(postorder, poststart + leftsize, postend - 1,
                            inorder, rootindex + 1, inend, mp);
        return root;
        
    }
};