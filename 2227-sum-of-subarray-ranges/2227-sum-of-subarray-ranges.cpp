class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        vector<int> nge(n);
        vector<int> pge(n);
        vector<int> nse(n);
        vector<int> pse(n);
       // int MOD = 1000000007;
        stack<int> st;
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty()&&nums[st.top()]<=nums[i])
            st.pop();
            if(st.empty()) nge[i]= n;
            else nge[i]= st.top();
            st.push(i);
        }
        st = stack<int>();
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty()&&nums[st.top()]>=nums[i])
            st.pop();
            if(st.empty()) nse[i]= n;
            else nse[i]= st.top();
            st.push(i);
        }
      st = stack<int>();
        for(int i=0;i<n;i++)
        {
            while(!st.empty()&&nums[st.top()]<nums[i])
            st.pop();
            if(st.empty()) pge[i]= -1;
            else pge[i]= st.top();
            st.push(i);
        }
       st = stack<int>();
        for(int i=0;i<n;i++)
        {
            while(!st.empty()&&nums[st.top()]>nums[i])
            st.pop();
            if(st.empty()) pse[i]= -1;
            else pse[i]= st.top();
            st.push(i);
        }
        long long ans = 0;
        for(int i = 0; i < n; i++) {
            long long left = i - pse[i];
            long long right = nse[i] - i;
            ans = (ans + (left * right ) * nums[i]);
        }
        long long an = 0;
        for(int i = 0; i < n; i++) {
            long long left = i - pge[i];
            long long right = nge[i] - i;
            an = (an + (left * right ) * nums[i]);
        }
        return an-ans;
    }
};