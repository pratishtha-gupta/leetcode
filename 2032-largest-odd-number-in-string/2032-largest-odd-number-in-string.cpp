class Solution {
public:
    string largestOddNumber(string s) {
        int end=-1,endi=-1;
        int n = s[s.size()-1]-'0';
        if(n&1) return s;
        for(int i=s.size()-1;i>=0;i--)
        {
            int n = s[i]-'0';
            if(n%2==1)
            {
                end = n;
                endi=i;
                break;
            }
        }
        if(endi==-1&&end==-1)
        return "";
        string ans ="";
        for(int i=0;i<=endi;i++)
        {
            ans+=s[i];
        }
        return ans;
    }
};