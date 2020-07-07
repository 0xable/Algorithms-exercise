class Solution {
public:
    // 240 ms
    // 96.1 MB
    int islandPerimeter(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        
        int result = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                if (!grid[i][j]) continue;
                result += 4;
                if (i > 0 && grid[i - 1][j]) --result;
                if (j > 0 && grid[i][j - 1]) --result;
                if (i + 1 < grid.size() && grid[i + 1][j]) --result;
                if (j + 1 < grid[i].size() && grid[i][j + 1]) --result;
            }
        }
        return result;
    }

    // 300 ms
    // 104.8 MB
    int islandPerimeter_(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        stack<pair<int, int>> coordinate;
        
        for (int i = 0; i < grid.size(); ++i) {
            if (!coordinate.empty()) break;
            for (int j = 0; j < grid[i].size(); ++j) {
                if (!grid[i][j]) continue;
                coordinate.push(make_pair(i, j));
                break;
            }
        }
        
        int i, j;
        int result = 0;
        while (!coordinate.empty()) {
            auto curr = coordinate.top();
            coordinate.pop();
            i = curr.first;
            j = curr.second;
            if (visited[i][j]) continue;
            
            visited[i][j] = true;
            result += 4;
            if (i > 0 && grid[i - 1][j]) {
                --result;
                coordinate.push(make_pair(i - 1, j));
            }
            if (j > 0 && grid[i][j - 1]) {
                --result;
                coordinate.push(make_pair(i, j - 1));
            }
            if (i + 1 < grid.size() && grid[i + 1][j]) {
                --result;
                coordinate.push(make_pair(i + 1, j));
            }
            if (j + 1 < grid[i].size() && grid[i][j + 1]) {
                --result;
                coordinate.push(make_pair(i, j + 1));
            }
        }
        return result;
    }

    // 224 ms
    // 96.2 MB
    int islandPerimeter__(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        
        int count = 0;
        int overlap = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                if (!grid[i][j]) continue;
                ++count;
                if (i + 1 < grid.size() && grid[i + 1][j]) ++overlap;
                if (j + 1 < grid[i].size() && grid[i][j + 1]) ++overlap;
            }
        }
        
        return 4 * count - 2 * overlap;
    }

    // 232 ms
    // 96.2 MB
    int islandPerimeter___(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        
        int count = 0;
        int overlap = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                if (!grid[i][j]) continue;
                ++count;
                if (i > 0 && grid[i - 1][j]) ++overlap;
                if (j > 0 && grid[i][j - 1]) ++overlap;
            }
        }
        
        return 4 * count - 2 * overlap;
    }
};