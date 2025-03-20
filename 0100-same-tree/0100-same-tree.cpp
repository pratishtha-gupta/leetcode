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
    //   void preorder1(TreeNode* p,vector<int>&ans1)
    //   {
    //       if(p==NULL) return;
    //       ans1.push_back(p->val);
    //       preorder1(p->left,ans1);
    //       preorder1(p->right,ans1);
    //   }
    //   void preorder2(TreeNode* q,vector<int>&ans2)
    //   {
    //       if(q==NULL) return;
    //       ans2.push_back(q->val);
    //       preorder2(q->left,ans2);
    //       preorder2(q->right,ans2);
    //   }
public:

    bool isSameTree(TreeNode* p, TreeNode* q) {
       if(p==NULL||q==NULL)
       return (p==q);
       return (p->val==q->val)&&isSameTree(p->left,q->left)&&isSameTree(p->right,q->right);

    }
};