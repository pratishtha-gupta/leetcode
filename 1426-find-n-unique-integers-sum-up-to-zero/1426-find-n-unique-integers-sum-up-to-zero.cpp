class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> v;
        if(n%2==0)
        {
            
            for(int i=1;i<=n/2;i++)
            {
                int num = i;
                v.push_back(num);
                num = -num;
                v.push_back(num);
            }

        }
        else
        {
            v.push_back(0);
            for(int i=1;i<=n/2;i++)
            {
                int num = i;
                v.push_back(num);
                num = -num;
                v.push_back(num);
            }

        }
        return v;
    }
};