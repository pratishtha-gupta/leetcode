class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n==0)
        return 0;
        unordered_set <int> st;
        int i;
        for(i=0;i<n;i++)
        {
            st.insert(nums[i]);
        }
        int cnt =0,ans =1;
        for(auto it: st)
        {
            if(st.find(it-1)==st.end())
            {
                cnt =1;
                while(st.find(it+1)!=st.end())
                {
                    it++;
                    cnt++;
                    ans = max(ans,cnt);
                }
            }
        }
        return ans;
    }
};