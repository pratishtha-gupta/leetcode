class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int sum=0;
        for(int i=0;i<apple.size();i++)
        {
            sum+=apple[i];
        }
        sort(capacity.begin(),capacity.end());
        reverse(capacity.begin(),capacity.end());
        int ans=0;
        for(int i=0;i<capacity.size();i++)
        {
            if(sum>0)
            {
                ans++;
                sum-=capacity[i];
            }
            else
            break;
        }
       return ans;
    }
};