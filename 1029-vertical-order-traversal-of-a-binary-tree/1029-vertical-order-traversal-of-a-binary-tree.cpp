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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        map<int,map<int,multiset<int>>> nodes;
        queue <pair<TreeNode*, pair<int,int>>> q;
        q.push({root,{0,0}});
        while(!q.empty())
        {
            auto temp = q.front();
            q.pop();
            int vertical = temp.second.first, level = temp.second.second;
            TreeNode* p = temp.first;
            nodes[vertical][level].insert(p->val);
            if(p->left!=NULL)
            {
                q.push({p->left,{vertical-1,level+1}});
            }
            if(p->right!=NULL)
            {
                q.push({p->right,{vertical+1,level+1}});
            }
        }
        for(auto a:nodes)
        {
            vector<int> col;
            for(auto b: a.second)
            {
                col.insert(col.end(),b.second.begin(),b.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};