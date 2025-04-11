class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int count =0;
        for(int i= low;i<=high;i++)
        {
            int sum1=0,sum2=0;
            string s = to_string(i);
            if(s.size()&1) continue;
            for(int j =0;j<s.size()/2;j++)
            {
               sum1+=(s[j]-'0');
            }
            for(int k=s.size()/2;k<s.size();k++)
            {
                sum2+=(s[k]-'0');
            }
            if(sum1==sum2) count++;
        }
        return count;
    }
};