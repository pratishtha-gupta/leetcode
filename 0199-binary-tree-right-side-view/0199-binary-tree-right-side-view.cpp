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
    vector<int> ds;
    public:
    void func( TreeNode* root,int level)
    {
        if(root==NULL) return;
        if(ds.size()==level) ds.push_back(root->val);
         func(root->right,level+1);
        func(root->left,level+1);
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        func(root,0);
        return ds;
    }
};