// https://leetcode.com/problems/word-search/

class Solution {
    int row, col;
    
public:
    // 332 ms
    // 187.6 MB
    bool exist(vector<vector<char>>& board, string word) {
        row = board.size();
        col = board[0].size();
        
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (board[i][j] == word[0] && search(board, i, j, word, 0)) return true;
            }
        }
        return false;
    }
    
    bool search(vector<vector<char>>& board, int x, int y, string word, int idx) {
        if (word.length() == idx) return true;
        if (x < 0 || x == row || y < 0 || y == col) return false;
        if (board[x][y] != word[idx]) return false;
        
        char curr = board[x][y];
        board[x][y] = '\0';
        bool result = search(board, x - 1, y, word, idx + 1)
                      || search(board, x + 1, y, word, idx + 1)
                      || search(board, x, y - 1, word, idx + 1)
                      || search(board, x, y + 1, word, idx + 1);
        board[x][y] = curr;
        return result;
    }
};