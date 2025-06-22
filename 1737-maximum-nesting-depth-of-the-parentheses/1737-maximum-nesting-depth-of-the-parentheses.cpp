class Solution {
public:
    int maxDepth(string s) {
        int val=0,ans=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
            {
                val++;
            }
            else if(s[i]==')')
            {
                ans = max(ans,val);
                val--;
            }
        }
        return ans;
    }
};