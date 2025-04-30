class Solution {
    int check(int num)
    {
        if(num==0)
        return 1;
        return log10(num)+1;
    }
public:
    int findNumbers(vector<int>& nums) {
        int n = nums.size();
        int count=0;
        for(int i=0;i<n;i++)
        {
            int number = nums[i];
            int noofdig = check(number);
            if(noofdig%2==0)
            count++;
        }
        return count;
    }
};