// https://algospot.com/judge/problem/read/TICTACTOE
// 4 ms

#include <iostream>
#include <vector>
#include <string>
#include <cassert>

using namespace std;

class Solution {
    vector<int> cache;
    vector<int> base;

public:
    Solution() : cache(19683, 0), base(9, 0) {
        base[0] = 1;
        for (int i = 1; i < 9; ++i) {
            base[i] = base[i - 1] * 3;
        }
        vector<vector<int>> board(3, vector<int>(3, 0));
        search(board, 0);
    }

    int search(vector<vector<int>> board, int turn) {
        int status = conversion(board);
        int curr = (turn % 2 == 0 ? 2 : 1);
        if (cache[status] != 0) return cache[status];
        return cache[status] = search(board, curr, turn);
    }

    int search(vector<vector<int>> board, int prev, int turn) {
        int status = conversion(board);
        if (cache[status] != 0) return cache[status];
        if (check(board, prev)) return cache[status] = prev;
        if (turn == 9) {
            return cache[status] = -1;
        }

        int curr = (prev == 1 ? 2 : 1);
        int result = 0;
        int bestWay = prev;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (board[i][j] == 0) {
                    board[i][j] = curr;
                    result = search(board, curr, turn + 1);
                    board[i][j] = 0;
                }
                if (result == curr) return cache[status] = curr;
                if (result == -1) bestWay = -1;
            }
        }
        return cache[status] = bestWay;
    }

    int conversion(vector<vector<int>>& board) {
        int result = 0;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                result += base[i * 3 + j] * board[i][j];
            }
        }
        return result;
    }

    bool check(vector<vector<int>>& board, int flag) {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (board[i][j] != flag) break;
                if (j == 2) return true;
            }
        }

        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (board[j][i] != flag) break;
                if (j == 2) return true;
            }
        }

        for (int i = 0; i < 3; ++i) {
            if (board[i][i] != flag) break;
            if (i == 2) return true;
        }

        for (int i = 2; i >= 0; --i) {
            if (board[2 - i][i] != flag) break;
            if (i == 0) return true;
        }
        return false;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    
    Solution s;
    string input;
    while (tc--) {
        vector<vector<int>> board(3, vector<int>(3, 0));
        int empty = 0;
        for (int i = 0; i < 3; ++i) {
            cin >> input;
            for (int j = 0; j < 3; ++j) {
                if (input[j] == 'x') {
                    board[i][j] = 1;
                } else if (input[j] == 'o') {
                    board[i][j] = 2;
                } else {
                    ++empty;
                } 
            }
        }

        int result = s.search(board, 9 - empty);        
        if (result == 1) {
            cout << 'x' << endl;
        } else if (result == 2) {
            cout << 'o' << endl;
        } else {
            cout << "TIE" << endl;
        }
    }
    return 0;
}