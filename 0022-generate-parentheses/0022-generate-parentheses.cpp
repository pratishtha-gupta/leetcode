class Solution {
public:
    void generate(string &str, int open, int close, int n, vector<string> &ans) {
        if (str.size() == 2 * n) {
            ans.push_back(str);
            return;
        }
        if (open < n) {
            str.push_back('(');
            generate(str, open + 1, close, n, ans);
            str.pop_back(); 
        }
        if (close < open) {
            str.push_back(')');
            generate(str, open, close + 1, n, ans);
            str.pop_back(); 
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string str;
        generate(str, 0, 0, n, ans); 
        return ans;
    }
};
