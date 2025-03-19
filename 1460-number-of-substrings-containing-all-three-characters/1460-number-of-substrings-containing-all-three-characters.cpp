class Solution {
public:
    int numberOfSubstrings(string s) {
        int st=0,cnt=0;
        int arr[3]={-1,-1,-1};
        for(int i=0;i<s.size();i++)
        {
            arr[s[i]-'a']=i;
            if(arr[0]!=-1&&arr[1]!=-1&&arr[2]!=-1)
            {
                cnt+=(1+min(arr[0],min(arr[1],arr[2])));
            }
        }
        return cnt;
    }
};