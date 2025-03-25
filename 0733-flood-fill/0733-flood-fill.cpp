class Solution {
public:
  
    void BFS(vector<vector<int>>& image, vector<vector<int>>& visited, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();
        visited[sr][sc] = 1;
        int initial = image[sr][sc];
        image[sr][sc] = color;

        queue<pair<int, int>> q;
        q.push({sr, sc});
        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            int first = node.first;
            int second = node.second;

            for (auto dir : directions) {
                int newRow = first + dir.first;
                int newCol = second + dir.second;

                if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n &&
                    image[newRow][newCol] == initial && visited[newRow][newCol] == 0) {
                    
                    q.push({newRow, newCol});
                    image[newRow][newCol] = color;
                    visited[newRow][newCol] = 1;
                }
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));

        if (image[sr][sc] != color) 
            BFS(image, visited, sr, sc, color);

        return image;
    }
};
