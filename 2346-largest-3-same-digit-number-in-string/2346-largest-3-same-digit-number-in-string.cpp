class Solution {
public:
    string largestGoodInteger(string nums) {
        string s;
        int n= nums.size();
        if(n<=2) return "";
        for(int i=0;i<=n-3;i++)
        {
            if(nums[i]==nums[i+1]&&nums[i+1]==nums[i+2])
            {
                string a= nums.substr(i,3);
                if(s.empty()) s= a;
                else
                {
                    if(a.back()>s.back()) s=a;
                }
                
            }
        }
        return s;
        
    }
};