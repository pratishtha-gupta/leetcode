class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int n = grid.size();
        int m = grid[0].size();
        int rem = grid[0][0]%x;
        int cnt =0;
        vector <int> v;
        int flag =0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]%x!= rem)
                {
                    flag=-1;
                }
                v.push_back(grid[i][j]);
            }
        }
        sort(v.begin(),v.end());
        int ind = (v.size()-1)/2;
        int el = v[ind];
        for(int i=0;i<v.size();i++)
        {
            cnt+= abs(el-v[i]);
        }
        if(flag==-1)
        return -1;
        else
        return cnt/x;
    }
};