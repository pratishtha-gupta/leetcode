class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size() > s.size()) return "";  // Edge case

        unordered_map<char, int> mp;
        for (char c : t) mp[c]++;  // Frequency map of characters in t
        
        int required = t.size(), left = 0, minLen = INT_MAX, start = -1;
        
        for (int right = 0; right < s.size(); right++) {
            if (mp[s[right]] > 0) required--; // Valid character in t found
            mp[s[right]]--;  // Decrease count
            
            while (required == 0) {  // Try to shrink window
                if (right - left + 1 < minLen) { // Found a smaller window
                    minLen = right - left + 1;
                    start = left;
                }
                
                mp[s[left]]++;  // Restore the left character
                if (mp[s[left]] > 0) required++; // If it's needed in t, increase required
                left++;  // Move left pointer
            }
        }
        
        return (start == -1) ? "" : s.substr(start, minLen);
    }
};
