class Solution {
public:
    string countAndSay(int n) {
    if (n == 1) return "1";

    string prev = countAndSay(n - 1);
    string result = "";

    int i = 0;
    while (i < prev.length()) {
        int count = 1;
        while (i + 1 < prev.length() && prev[i] == prev[i + 1]) {
            count++;
            i++;
        }
        result += to_string(count) + prev[i];
        i++;
    }

    return result;
}

};