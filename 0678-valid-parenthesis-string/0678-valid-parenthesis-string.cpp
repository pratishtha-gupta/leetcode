class Solution {
public: 
    bool checkValidString(string s) {
        stack<int> openBrackets; // Stack to store indices of open brackets
        stack<int> asterisks; // Stack to store indices of asterisks

        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];

            // If current character is an open bracket, push its index onto the stack
            if (ch == '(') {
                openBrackets.push(i);
                // If current character is an asterisk, push its index onto the stack
            } else if (ch == '*') {
                asterisks.push(i);
                // current character is a closing bracket ')'
            } else {
                if (!openBrackets.empty()) {
                    openBrackets.pop();
                } else if (!asterisks.empty()) {
                    asterisks.pop();
                } else {
                    return false;
                }
            }
        }
        while (!openBrackets.empty() && !asterisks.empty()) {
            if (openBrackets.top() > asterisks.top()) {
                return false; 
            }
            openBrackets.pop();
            asterisks.pop();
        }
        return openBrackets.empty();
    }
};