class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        priority_queue<int, vector<int>, greater<int>> pq;
        
        int i = 0, n = events.size();
        int day = 1, attended = 0;
        int maxDay = 0;
        for (auto& event : events)
            maxDay = max(maxDay, event[1]);
        for (day = 1; day <= maxDay; ++day) {
            while (i < n && events[i][0] == day)
                pq.push(events[i++][1]);
            while (!pq.empty() && pq.top() < day)
                pq.pop();
            if (!pq.empty()) {
                pq.pop();
                attended++;
            }
        }

        return attended;
    }
};
