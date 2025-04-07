class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char,char> mp;
        for(int i=0;i<s.size();i++)
        {
            if(mp.find(s[i])==mp.end())
            {
                mp[s[i]]=t[i];
            }
            else
            {
                if (mp[s[i]]==t[i]) continue;
                else
                return false;
            }
        }
         map<char,char> mpi;
        for(int i=0;i<s.size();i++)
        {
            if(mpi.find(t[i])==mpi.end())
            {
                mpi[t[i]]=s[i];
            }
            else
            {
                if (mpi[t[i]]==s[i]) continue;
                else
                return false;
            }
        }
        return true;
    }
};