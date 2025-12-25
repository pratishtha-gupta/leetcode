class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {

        sort(happiness.begin(),happiness.end());
        int n = happiness.size();
        int ind = n-1;
        long long sum=0;
        for(int i= n-k;i<n;i++)
        {
           int x = ind-i;
           if(happiness[i]-x<0)
           {
             sum+=0;
           }
           else
           {
              sum+=(happiness[i]-x);
           }
        }
      return sum;
        
    }
};