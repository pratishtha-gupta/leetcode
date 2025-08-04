class Solution {
public:
    int minBitFlips(int start, int goal) {
        int a = start, b=goal;
        int ans=0;
        while(b!=0||a!=0)
        {
            if((b&1)!=(a&1))
            ans++;
            b=b>>1;
            a=a>>1;
        }
        return ans;
    }
};