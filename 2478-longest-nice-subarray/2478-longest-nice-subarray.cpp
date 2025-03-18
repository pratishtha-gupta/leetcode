class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int r=0,l=0,maxlen=0,n=nums.size(),number=0;
        while(r<n)
        {
            while((number&nums[r])!=0)
            {
                number = number^nums[l];
                l++;   
            }
            number = number|nums[r];
            maxlen=max(maxlen,r-l+1);
            r++;
        }
        return maxlen;
    }
};
