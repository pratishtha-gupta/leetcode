class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> ans;

        for (int i = 0; i < s.size(); i += k) {
            string news = "";
            for (int j = i; j < i + k && j < s.size(); j++) {
                news += s[j];
            }
            while (news.size() < k) {
                news += fill;
            }
            ans.push_back(news);
        }

        return ans;
    }
};
