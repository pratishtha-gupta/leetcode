class Solution {
    bool check(int mid, vector<int>& bloomDay, int m, int k) {
        int boq=0,curr=0;
        for(int i=0;i<bloomDay.size();i++)
        {
            if(bloomDay[i]>mid)
            {
                if(curr>=k) boq+= (curr/k);
                curr=0;
            }
            else
            curr++;
        }
        if(curr>=k) boq+=(curr/k);
        if (boq >= m)
            return true;
        else
            return false;
    }

public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int low = 1, high = *max_element(bloomDay.begin(), bloomDay.end());
        int ans = high;
        long long mul = 1ll*m*k;
        if( mul > bloomDay.size()) return -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (check(mid, bloomDay, m, k)) {
                ans = mid;
                high = mid - 1;
            } else
                low = mid + 1;
        }
        return ans;
    }
};