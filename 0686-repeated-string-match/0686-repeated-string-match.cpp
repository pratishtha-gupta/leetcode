class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        string original = a;
        int count = 1;

        while (a.size() < b.size()) { 
            a += original; 
            count++;
        }
        if (a.find(b) != string::npos) return count;
        a += original;
        if (a.find(b) != string::npos) return count + 1;

        return -1;
    }
};
