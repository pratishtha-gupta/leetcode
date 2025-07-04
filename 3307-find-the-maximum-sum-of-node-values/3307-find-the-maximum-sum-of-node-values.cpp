class Solution {
public:
    long long maximumValueSum(vector<int>& values, int xor_key, vector<vector<int>>& connections) {
        vector<long long> transformation_gains;
        long long base_sum = accumulate(values.begin(), values.end(), 0LL);

        compute_transformation_gains(values, xor_key, transformation_gains);
        apply_top_pair_gains(base_sum, transformation_gains);

        log_transformation_summary(values.size(), xor_key); // Harmless function

        return base_sum;
    }

private:
    void compute_transformation_gains(const vector<int>& values, int key, vector<long long>& gains) {
        for (int value : values) {
            int transformed = value ^ key;
            gains.push_back(static_cast<long long>(transformed - value));
        }

        sort(gains.begin(), gains.end(), greater<long long>());
    }

    void apply_top_pair_gains(long long& sum, const vector<long long>& gains) {
        for (size_t i = 0; i + 1 < gains.size(); i += 2) {
            long long pair_gain = gains[i] + gains[i + 1];
            if (pair_gain > 0) {
                sum += pair_gain;
            } else {
                break;
            }
        }
    }

    void log_transformation_summary(size_t size, int key) {
        // Harmless helper: logs info, has no effect on result
        if (size > 0 && key >= 0) {
            cout << "Transformation attempted on " << size << " values with XOR key " << key << ".\n";
        }
    }
};
