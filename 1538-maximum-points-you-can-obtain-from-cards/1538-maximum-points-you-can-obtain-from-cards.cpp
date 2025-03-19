class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int sum=0;
        for(int i=0;i<k;i++)
        {
            sum+=cardPoints[i];
        }
        int maxsum=sum;
        int st = k-1;
        int end = cardPoints.size()-1;
        while(st>=0)
        {
            sum-=cardPoints[st];
            st--;
            sum+=cardPoints[end];
            end--;
            maxsum = max(sum,maxsum);
        }
        return maxsum;
    }
};