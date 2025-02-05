class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int i,ct=0,arr[2],j=0;
        for(i=0;i<s1.length();i++)
        {
           if(s1[i]!=s2[i])
           {
           ct++;
           if(j>1)
           break;
           arr[j]=i;
           j++;
           }
        }
    if(ct==0)
    return true;
    else if(ct==2)
    {
        char a = s1[arr[0]];
        char b = s1[arr[1]];
        char c = s2[arr[0]];
        char d = s2[arr[1]];
        if(a==d&&b==c)
        return true;
        else 
        return false;
    }
    else
    return false;
    }
};