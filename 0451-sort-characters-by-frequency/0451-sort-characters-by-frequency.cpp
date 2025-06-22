class Solution {
public:
    string frequencySort(string s) {
        map <char,int> mp;
        for(auto ch: s)
        {
            mp[ch]++;
        }
        vector<pair<char,int>> v(mp.begin(),mp.end());
        sort(v.begin(),v.end(),[](pair<char,int> &a,pair<char,int> &b)
        {
            return a.second>b.second;
        });
        string ans="";
        for(auto it:v)
        {
           string curr="";
           for(int i=0;i<it.second;i++)
           {
              curr+=it.first;
           }
           ans+=curr;
        }
        return ans;
    }
};