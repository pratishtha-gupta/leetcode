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
    TreeNode* insertIntoBST(TreeNode* root, int k) {
        if(root==NULL) return new TreeNode(k);
        TreeNode* cur= root;
        while(true)
        {
            if(cur->val<k)
            {
                if(cur->right!=NULL)
                {
                    cur = cur->right;
                }
                else
                {
                    cur->right = new TreeNode(k);
                    break;
                }
            }
            else
            {
                if(cur->left!=NULL)
                {
                    cur = cur->left;
                }
                else
                {
                    cur->left = new TreeNode(k);
                    break;
                }

            }
            
        }
        return root;
    }
};