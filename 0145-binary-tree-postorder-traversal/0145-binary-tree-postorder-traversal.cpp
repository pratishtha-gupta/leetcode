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
    vector<int> postorderTraversal(TreeNode* root) {
        if(root==NULL)
        return {};
        stack <TreeNode*> st1,st2;
        vector<int> postorder;
        TreeNode* temp;
        st1.push(root);
        while(!st1.empty())
        {
            temp= st1.top();
            st2.push(temp);
            st1.pop();
            if(temp->left!=NULL)
            st1.push(temp->left);
            if(temp->right!=NULL)
            st1.push(temp->right);
        }



        while(!st2.empty())
        {
            TreeNode* node = st2.top();
            st2.pop();
            postorder.push_back(node->val);
        }
        return postorder;
    }
};