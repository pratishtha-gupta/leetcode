class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int r=0,l=0,maxlen=0,maxf=0,len=0;
        map<int,int>mp;
        while(r<fruits.size())
        {
            mp[fruits[r]]++;
            
            if(mp.size()>2)
            {
                mp[fruits[l]]--;
                if(mp[fruits[l]]==0) mp.erase(fruits[l]);
                l++;
            }
            len = r-l+1;
            maxlen = max(len,maxlen);
            r++;
        }
        return maxlen;
    }
};
