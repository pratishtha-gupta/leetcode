class Solution {
public:
    int longestValidParentheses(string s) {
    int n = s.size();
    stack<pair<char,int>> st;

    for(int i = 0; i < n; i++) {
        if(s[i] == '(') {
            st.push({s[i], i});
        } else {
            if(!st.empty() && st.top().first == '(')
                st.pop();
            else
                st.push({s[i], i});
        }
    }

    if(st.empty()) return n;

    int ans = 0;
    int prev = n; 
    while(!st.empty()) {
        auto cur = st.top(); st.pop();
        ans = max(ans, prev - cur.second - 1);
        prev = cur.second;
    }
    ans = max(ans, prev);
    
    return ans;
}

};