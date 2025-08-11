class Solution {
public:
    string minWindow(string s, string t) {
        int left =0,minlen = INT_MAX, start=-1,required=0,right=0;
        map<char,int> mp;
        if(s.size()<t.size()) return "";
        for(auto c:t) 
        {
            mp[c]++;
            required++;
        }
        while(right<s.size())
        {
            if(mp[s[right]]>0) required--;
            mp[s[right]]--;
            while(required==0){
            if(right-left+1 < minlen)
            {
                minlen = right-left+1;
                start = left;
            }
            
           mp[s[left]]++;
           if(mp[s[left]]>0) required++;
           left++;
            }
           right++;
            
        }
        if(start!=-1)
        return s.substr(start,minlen);
        else
        return "";
    }
};