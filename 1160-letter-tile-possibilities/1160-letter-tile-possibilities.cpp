class Solution {
    private:
    int sequence (int alp[26])
    {
       int ans =0;
       for(int i=0;i<26;i++)
       {
          if(alp[i]==0)
          continue;
          ans++;
          alp[i]--;
          ans+=sequence(alp);
          alp[i]++;
       }
       return ans;
    }
public:
    int numTilePossibilities(string tiles) {
       int alp[26]={0};
       for(auto it: tiles)
       {
           alp[it-'A']++;
       }
       return sequence(alp);
    }
};