// https://leetcode.com/problems/unique-paths-iii/
// 0 ms
// 7.1 MB

class Solution {
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int emptyCount = 0;
        int startRow, startCol;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                if (grid[i][j] == 0) {
                    ++emptyCount;
                } else if (grid[i][j] == 1) {
                    startRow = i;
                    startCol = j;
                }
            }
        }
        
        int result = 0;
        grid[startRow][startCol] = -1;
        search(grid, startRow, startCol, emptyCount + 1, result);
        return result;
    }
    
    void search(vector<vector<int>>& grid, int row, int col, int emptyCount, int& result) {
        if (emptyCount == 0) {
            if (grid[row][col] == 2) ++result;
            return;
        }
        if (grid[row][col] == 2) return;
        
        grid[row][col] = -1;
        if (row + 1 < grid.size() && grid[row + 1][col] != -1) search(grid, row + 1, col, emptyCount - 1, result);
        if (row - 1 >= 0 && grid[row - 1][col] != -1) search(grid, row - 1, col, emptyCount - 1, result);
        if (col + 1 < grid[row].size() && grid[row][col + 1] != -1) search(grid, row, col + 1, emptyCount - 1, result);
        if (col - 1 >= 0 && grid[row][col - 1] != -1) search(grid, row, col - 1, emptyCount - 1, result);
        grid[row][col] = 0;
        return;
    }
};