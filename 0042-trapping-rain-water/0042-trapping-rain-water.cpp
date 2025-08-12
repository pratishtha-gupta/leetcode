class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int l=0,r=n-1;
        int res=0;
        int maxleft=0,maxright=0;
        while(l<=r)
        {
            if(height[l]<=height[r])
            {
                if(height[l]>=maxleft)
                {
                    maxleft= height[l];
                }
                else
                res+= maxleft-height[l];
                l++;
            }
            else
            {
                if(height[r]>=maxright)
                maxright = height[r];
                else
                res+= maxright-height[r];
                r--;
            }
        }
        return res;
    }
};