class Solution {
public:
    int minimumDeletions(string word, int k) {
        unordered_map<char, int> freq;
        for (char c : word) {
            freq[c]++;
        }

        vector<int> freqs;
        for (auto [c, count] : freq) {
            freqs.push_back(count);
        }

        sort(freqs.begin(), freqs.end());

        int n = freqs.size();
        int total = 0;
        for (int f : freqs) total += f;

        int ans = INT_MAX;

        for (int i = 0; i < n; ++i) {
            int target = freqs[i];
            int deletions = 0;

            // delete all frequencies less than target
            for (int j = 0; j < i; ++j)
                deletions += freqs[j];

            // delete partial frequencies greater than target + k
            for (int j = i; j < n; ++j) {
                if (freqs[j] > target + k)
                    deletions += freqs[j] - (target + k);
            }

            ans = min(ans, deletions);
        }

        return max(0, ans);
    }
};
