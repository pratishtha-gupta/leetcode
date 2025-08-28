class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        vector<int> even;
        vector<int> odd;
        for(int i=0;i<nums.size();i++)
        {
            if(i&1)
            odd.push_back(nums[i]);
            else
            even.push_back(nums[i]);
        }
        sort(even.begin(),even.end());
        sort(odd.begin(),odd.end(),greater<int>());
        int i=0,j=0;
        for(int k=0;k<nums.size();k++)
        {
            if(k&1)
            {
                nums[k]=odd[j];
                j++;
            }
            else
            {
                nums[k]=even[i];
                i++;
            }
        }
        return nums;

    }
};