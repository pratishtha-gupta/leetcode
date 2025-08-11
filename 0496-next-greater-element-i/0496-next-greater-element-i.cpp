class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nge(nums2.size());
        stack<int> st;
        for(int i=nums2.size()-1;i>=0;i--)
        {
            while(!st.empty()&&st.top()<=nums2[i])
            {
                st.pop();
            }
            if(st.empty()) nge[i]=-1;
            else nge[i]= st.top();
            st.push(nums2[i]);
        }
        vector<int> ans;
        for(auto it:nums1)
        {
            for(int i=0;i<nums2.size();i++)
            {
                if(it==nums2[i])
                ans.push_back(nge[i]);
            }
        }
        return ans;
    }
};