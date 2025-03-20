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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL)
        return ans;
        int flag=0;
        queue <TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int n = q.size();
            vector <int> level(n);
            for(int i=0;i<n;i++)
            {
                TreeNode* node = q.front();
                q.pop();
                if(flag==0)
                {
                    level[i] = node->val;
                }
                else
                level[(n-1)-i]= node->val;
                if(node->left!=NULL)
                q.push(node->left);
                if(node->right!=NULL)
                q.push(node->right);
            }
            flag = !flag;
            ans.push_back(level);
        }
        return ans;
    }
};