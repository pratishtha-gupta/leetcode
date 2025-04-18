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
int maxi=INT_MIN;
   int maxpath(TreeNode* root)
   {
       if(root==NULL)
       return 0;
       int leftsum = max(0,maxpath(root->left));
       int rightsum = max(0,maxpath(root->right));
       maxi = max(maxi,leftsum+rightsum+root->val);
       return root->val+ max(leftsum,rightsum);
   }
public:
    int maxPathSum(TreeNode* root) {
        int a=maxpath(root);
        return maxi;
    }
};