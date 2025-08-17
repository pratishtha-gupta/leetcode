class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
    map<char,int> mp;
    for (char t : tasks) {
        mp[t]++;
    }

    int maxi = 0;
    for (auto &p : mp) {
        maxi = max(maxi, p.second);  
    }

    int count_max = 0;
    for (auto &p : mp) {
        if (p.second == maxi) count_max++; 
    }

    int min_time = (maxi - 1) * (n + 1) + count_max;

    return max((int)tasks.size(), min_time);
}

};