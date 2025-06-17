class Solution {
public:
    vector<int> majorityElement(vector<int>& v) {
        int cnt1 = 0, cnt2 = 0, el1 = INT_MIN, el2 = INT_MIN;
        int n = v.size();
        for (int i = 0; i < n; i++) {
            if(cnt1==0&&el2!=v[i])
            {
               el1 = v[i];
               cnt1=1;
            }
            else if(cnt2==0 && el1!=v[i])
            {
                el2 = v[i];
                cnt2=1;
            }
            else if(el1==v[i]) cnt1++;
            else if(el2==v[i]) cnt2++;
            else
            {
                cnt1--;
                cnt2--;
            }
        }
        cnt1=0,cnt2=0;
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            if(el1==v[i]) cnt1++;
            if(el2==v[i]) cnt2++;
            

        }
        if(cnt1>(n/3)) ans.push_back(el1);
        if(cnt2>(n/3)) ans.push_back(el2);
        sort(ans.begin(),ans.end());
        return ans;
    }
};