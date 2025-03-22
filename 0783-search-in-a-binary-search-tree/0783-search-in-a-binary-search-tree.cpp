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
    TreeNode* searchBST(TreeNode* root, int valu) {
        if(root==NULL) return root;
        while(root!=NULL)
        {
            if(root->val == valu)
            return root;
            else if(valu>root->val)
            root= root->right;
            else
            root = root->left;
        }
        return root;
    }
};