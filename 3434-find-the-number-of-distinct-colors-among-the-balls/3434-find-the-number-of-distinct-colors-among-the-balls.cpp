#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        map<int, int> ballColor;         
        map<int, int> colorCount;       
        vector<int> ans;
        int distinctColors = 0;          

        for (auto& query : queries) {
            int ball = query[0];
            int newColor = query[1];
            if (ballColor.count(ball)) {
                int oldColor = ballColor[ball];
                if (oldColor == newColor) {
                    ans.push_back(distinctColors);
                    continue;
                }
               
                colorCount[oldColor]--;
                if (colorCount[oldColor] == 0) {
                    distinctColors--; 
                }
            }
            ballColor[ball] = newColor;
            if (colorCount[newColor] == 0) {
                distinctColors++; 
            }
            colorCount[newColor]++;

            ans.push_back(distinctColors);
        }
        return ans;
    }
};
