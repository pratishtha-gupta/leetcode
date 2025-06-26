class Solution {
public:
    int longestSubsequence(string binaryStr, int maxVal) {
        int currentSum = 0;
        int length = 0;
        int maxBits = 32 - __builtin_clz(maxVal);

        for (int index = 0; index < binaryStr.size(); ++index) {
            char currentChar = binaryStr[binaryStr.size() - 1 - index];
            
            if (currentChar == '1') {
                if (index < maxBits && currentSum + (1 << index) <= maxVal) {
                    currentSum += (1 << index);
                    length++;
                }
            } else {
                length++;
            }
        }

        return length;
    }
};
