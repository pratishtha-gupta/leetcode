class Solution {
    void backtrack(int i, string path, long res, int prev,vector<string> &ans, string num,int target)
    {
        if(i==num.size())
        {
           if(res==target) ans.push_back(path);
           return;
        }
        long number = 0;
        string numstr;
        for(int j=i;j<num.size();j++)
        {
            if(j>i&&num[i]=='0') break;
            numstr+=num[j];
            number = number*10+num[j]-'0';
            if(i==0)
            {
                backtrack(j+1,path+numstr,number,number,ans,num,target);
            }else{
            backtrack(j+1,path+'+'+numstr,number+res,number,ans,num,target);
            backtrack(j+1,path+'-'+numstr,-number+res,-number,ans,num,target);
            backtrack(j+1,path+'*'+numstr,res-prev+prev*number,number*prev,ans,num,target);
            }
        }
    }
public:
    vector<string> addOperators(string num, int target) {
       vector<string> ans;
       backtrack(0,"",0,0,ans,num,target);
       return ans;
        
    }
};