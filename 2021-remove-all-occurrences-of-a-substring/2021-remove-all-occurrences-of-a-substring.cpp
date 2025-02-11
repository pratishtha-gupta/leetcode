class Solution {
private:
 bool check(stack<char> &st,string &part, int a)
 {
    stack <char> stk = st;
    for(int i=a-1;i>=0;i--)
    {
        if(stk.top()!=part[i])
        {
            return false;
        }
        stk.pop();
    }
    return true;
 }
public:
    string removeOccurrences(string s, string part) {
        stack <char> st;
        int n = s.length(), a=part.length();
        for(int i=0;i<n;i++)
        {
            st.push(s[i]);
            if(st.size()>=a&&check(st,part,a))
            {
            for(int j=0;j<a;j++)
            {
                st.pop();
            }
            }
        }
        string ans="";
        while(!st.empty())
        {
            ans=st.top()+ans;
            st.pop();
        }
        return ans;
    }
};