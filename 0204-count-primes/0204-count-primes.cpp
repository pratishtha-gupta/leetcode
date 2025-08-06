class Solution {
    vector<bool> sieveoferas(int n)
    {
        vector<bool> a(n+1,true);
        for(int p=2;p*p<=n;p++)
        {
            if(a[p]==true)
            {
                for(int i=p*p;i<=n;i+=p)
                {
                    a[i]=false;
                }
            }
        }
        return a;
    }
public:
    int countPrimes(int n) {
        int cnt =0;
        
        vector<bool> ans = sieveoferas(n);
        for(int i=2;i<n;i++)
        {
            if(ans[i]==true)
            cnt++;
        }
        return cnt;
    }
};