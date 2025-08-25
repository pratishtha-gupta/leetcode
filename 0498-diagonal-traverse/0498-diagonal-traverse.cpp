class Solution {
    void find(int i, int j, vector<vector<int>>&mat, vector<int> &ans, int n, int m,int &f)
    {
        vector<int> s;
        while(i<=n&&j>=0)
        {
            int val = mat[i][j];
            i++;
            j--;
            s.push_back(val);
        }
        if(f==0)
        {
            ans.insert(ans.end(),s.begin(),s.end());
        }
        else
        {
            reverse(s.begin(),s.end());
            ans.insert(ans.end(),s.begin(),s.end());
        }
        f = f^1;
    }
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> ans;
        int n = mat.size()-1;
        int m = mat[0].size()-1;
        int f=1;
        for(int i=0;i<=m;i++)
        {
            find(0,i,mat,ans,n,m,f);
        }
        for(int i=1;i<=n;i++)
        {
            find(i,m,mat,ans,n,m,f);
        }

        return ans;
    }
};