class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int ans=-1;
       sort(nums.begin(),nums.end());
       for(int i=0;i<nums.size();i++)
       {
          if(nums[i]!=i){
          ans = i;
          break;
          }
       }
       if(ans==-1)
       ans = nums.size();
       return ans;
    }
};