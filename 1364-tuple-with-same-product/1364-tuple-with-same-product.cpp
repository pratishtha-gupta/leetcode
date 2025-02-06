class Solution {
    int combination (int n,int r)
    {
        return (n*(n-1))/2;
    }
public:
    int tupleSameProduct(vector<int>& nums) {
        map <int,int> mp;
        int ans =0;
        for(int i=0;i<nums.size();i++)
        {
            for(int j=i+1;j<nums.size();j++)
            {
                int prod = nums[i]*nums[j];
                mp[prod]++;
            }
        }
        for(auto it: mp)
        {
            if(it.second>=2)
            {
                int x = combination(it.second,2);
                ans+= (x*8);
            }
        }
        return ans;
    }
};