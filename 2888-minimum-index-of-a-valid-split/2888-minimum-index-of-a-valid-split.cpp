class Solution {
public:
    int minimumIndex(vector<int>& nums) {
      int n = nums.size();
      unordered_map<int, int> freqMap;
    int maxElement = -1, maxCount = 0;
    for (int num : nums) {
        freqMap[num]++;
        if (freqMap[num] > maxCount) {
            maxCount = freqMap[num];
            maxElement = num;
        }
    }
    int ct=0,split;
    for(int i=0;i<n;i++)
    {
       if(nums[i]==maxElement)
       ct++;
       if(ct>(i+1)/2)
       {
          split=i;
          break;
       }
    }
    int c=0;
    for(int i=split+1;i<n;i++)
    {
        if(nums[i]==maxElement)
        c++;
    }
    if(c>((n-1)-(split+1)+1)/2)
    return split;
    else
    return -1;
    }
};