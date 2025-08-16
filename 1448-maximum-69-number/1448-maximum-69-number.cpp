class Solution {
public:
    int maximum69Number (int num) {
        int n = num;
        int rev=0;
        while(n>0)
        {
            int rem = n%10;
            rev = rev*10+rem;
            n = n/10;
        }
        int f=0,nu=0;
        while(rev>0)
        {
            int dig = rev%10;
            if(dig==6&&f==0)
            {
               nu = nu*10+9;
               f=1;
            }
            else 
            nu = nu*10+dig;
            rev = rev/10;
        }
        // int ans=0;
        // while(nu>0)
        // {
        //     int rem = nu%10;
        //     ans = ans*10+rem;
        //     nu = nu/10;
        // }
        return nu;
    }
};