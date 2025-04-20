class Solution {
public:
    int numRabbits(vector<int>& answers) {
       for(int i=0;i<answers.size();i++)
       {
        answers[i]++;
       }
       unordered_map<int,int> mp;
       //element,count
       for(auto it: answers)
       {
           mp[it]++;
       }
       int ans =0;
       for(auto it:mp)
       {
           if(it.second==it.first)
           {
               ans+=it.second;
           }
           else if(it.second>it.first)
           {
              int val = it.first* ceil((double)it.second/it.first);
              ans+=val;

           }
           else 
           ans+=it.first;
       }
       return ans;
    }
};