class Solution {
public:
    int possibleStringCount(string word) {
        int i,ct=1,ans=0;
        int n = word.size();
        for (int i = 1; i < n; i++) {
            if(word[i]==word[i-1])
            {
                ct++;
            }
            else
            {
                if(ct>1)
                {
                    ans+=(ct-1);
                }
                ct=1;
            }
        }
        if(ct>1)
                {
                    ans+=(ct-1);
                }
                return ans+1;
    }
};