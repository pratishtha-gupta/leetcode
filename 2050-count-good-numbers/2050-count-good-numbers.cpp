class Solution {
    public:
    long long power( long long num,long long a, long long mod)
    {
        long long ans =1;
        long long n = a;
        while(n>0)
        {
            if(n&1)
            {
                ans = (ans *num)%mod;
                n = n-1;
            }
            else
            {
                num = (num*num)%mod;
                n = n/2;
            }
        }
        return ans;
    }
public:
    int countGoodNumbers(long long n) {
         long long mod =1e9+7;
        long long a = n/2;
        long long num =20;
        long long ans = power (num,a,mod);
        if(n&1)
        ans = (ans*5)%mod;
        return ans;
    }
};