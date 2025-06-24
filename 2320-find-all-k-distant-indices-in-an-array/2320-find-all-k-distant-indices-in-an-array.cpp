class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
       vector<int> indexes;
       for(int i=0;i<nums.size();i++)
       {
           if(nums[i]==key) indexes.push_back(i);
       }
       set <int> st;
       for(int i=0;i<nums.size();i++)
       {
           for(int j=0;j<indexes.size();j++)
           {
              if(abs(i-indexes[j])<=k)
              st.insert(i);
           }
       }
       vector<int> ans(st.begin(),st.end());
       return ans;
    }
};