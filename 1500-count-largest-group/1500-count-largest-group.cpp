class Solution {
public:
    int countLargestGroup(int n) {
        map <int,int> mp;
        for(int i=1;i<=n;i++)
        {
            int num = i;
            int sum=0;
            while(num>0)
            {
                int rem = num%10;
                sum+=rem;
                num = num/10;
            }
            mp[sum]++;
        }
        int ans =0;
        for(auto it:mp)
        {
            if(it.second>ans)
            ans = it.second;
        }
         int count = 0;
        for (auto it : mp) {
            if (it.second == ans) {
                count++;
            }
        }

        return count;
    }
};