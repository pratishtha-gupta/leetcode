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
class BSTIterator {
    stack <TreeNode*> st;
    void pushall(TreeNode* root)
    {
        while(root)
        {
            st.push(root);
            root= root->left;
        }
    }
public:
    BSTIterator(TreeNode* root) {
      pushall(root);
    }
    
    int next() {
        TreeNode* tmp =st.top();
        st.pop();
        pushall(tmp->right);
        return tmp->val;
    }
    
    bool hasNext() {
        if(st.empty())
        return false;
        else
        return true;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */