class Solution {
    public:
    int fibo(int n)
    {
        if(n==0)
        return 0;
        int last =1,sec=0,cur;
        for(int i=2;i<=n;i++)
        {
            cur = last+sec;
            sec=last;
            last = cur;
        }
        return cur;
    }
public:
    int fib(int n) {
        int ans = fibo(n);
        return ans;
    }
};