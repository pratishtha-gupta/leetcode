class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        vector <int> pairsum;
        for(int i=0;i<weights.size()-1;i++)
        {
            long long sum = weights[i]+weights[i+1];
            pairsum.push_back(sum);
        }
        sort(pairsum.begin(),pairsum.end());
        long long minsum=0,maxsum=0;
        for(int i=0;i<k-1;i++)
        {
            minsum+=pairsum[i];
            maxsum+=pairsum[pairsum.size()-(i+1)];
        }
        return maxsum-minsum;
    }
};