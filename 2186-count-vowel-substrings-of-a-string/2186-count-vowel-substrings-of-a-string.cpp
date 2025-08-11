class Solution {
    bool isvowel(char ch) {
        return ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u';
    }

    int func(string &s, int k) {
        unordered_map<char,int> mp;
        int ct = 0, l = 0, r = 0;

        while (r < s.size()) {
            if (!isvowel(s[r])) { // consonant → reset window
                mp.clear();
                l = r + 1;
                r++;
                continue;
            }

            mp[s[r]]++;
            while (mp.size() > k) {
                if (--mp[s[l]] == 0) mp.erase(s[l]);
                l++;
            }

            ct += (r - l + 1);
            r++;
        }
        return ct;
    }

public:
    int countVowelSubstrings(string word) {
        return func(word, 5) - func(word, 4);
    }
};
