class Solution {
public:
    string clearDigits(string s) {
        string ans="";
        for(int i=0;i<s.size();i++)
        {
            if(s[i]>='a'&&s[i]<='z')
            {
                ans.push_back(s[i]);
            }
            else
            {
                ans.pop_back();
            }
        }
        return ans;
    }
};