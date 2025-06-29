class Solution {
public:
    void dfs(vector<vector<int>>& image, int i, int j, int color, int oldColor) {
        int m = image.size(), n = image[0].size();
        if (i < 0 || j < 0 || i >= m || j >= n || image[i][j] != oldColor) return;

        image[i][j] = color;

        dfs(image, i + 1, j, color, oldColor);
        dfs(image, i - 1, j, color, oldColor);
        dfs(image, i, j + 1, color, oldColor);
        dfs(image, i, j - 1, color, oldColor);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int oldColor = image[sr][sc];
        if (oldColor != color)
            dfs(image, sr, sc, color, oldColor);
        return image;
    }
};
