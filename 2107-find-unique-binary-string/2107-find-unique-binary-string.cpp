

class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        unordered_set<int> binaryNumbers;
        
        for (const string& s : nums) {
            binaryNumbers.insert(stoi(s, nullptr, 2)); // Convert binary string to decimal
        }
        
        for (int i = 0; i < (1 << n); ++i) { // Iterate over all possible n-bit numbers
            if (binaryNumbers.find(i) == binaryNumbers.end()) { // Find a missing number
                string result = bitset<16>(i).to_string(); // Convert to binary string
                return result.substr(16 - n); // Get last n bits
            }
        }
        
        return ""; // Should never reach here
    }
};
