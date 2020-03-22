// https://algospot.com/judge/problem/read/BOARDCOVER

#include <iostream>
#include <vector>
#include <string>
#include <utility>

using namespace std;

class Solution {
    int row, col;
    int count;
    int remain;
    vector<vector<char>> board;
public:
    Solution(int row, int col, vector<vector<char>>&& board) : row{row}, col{col}, board{board} {
        count = 0;
        remain = 0;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (board[i][j] == '.') remain++;
            }
        }
        if (remain % 3 == 0) {
            search();
        }
    }

    void search() {
        int x = -1;
        int y = -1;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (board[i][j] == '.') {
                    x = j;
                    y = i;
                    break;
                }
            }
            if (x != -1) break;
        }
        if (x == -1) {
            count++;
            return;
        }

        if (x + 1 < col && board[y][x + 1] == '.' && y + 1 < row && board[y + 1][x] == '.') {
            board[y + 1][x] = board[y][x + 1] = board[y][x] = '#';
            search();
            board[y + 1][x] = board[y][x + 1] = board[y][x] = '.';
        }

        if (x + 1 < col && board[y][x + 1] == '.' && y + 1 < row && board[y + 1][x + 1] == '.') {
            board[y][x + 1] = board[y + 1][x + 1] = board[y][x] = '#';
            search();
            board[y][x + 1] = board[y + 1][x + 1] = board[y][x] = '.';
        }

        if (y + 1 < row && board[y + 1][x] == '.' && x - 1 >= 0 && board[y + 1][x - 1] == '.') {
            board[y + 1][x] = board[y + 1][x - 1] = board[y][x] = '#';
            search();
            board[y + 1][x] = board[y + 1][x - 1] = board[y][x] = '.';
        }

        if (y + 1 < row && board[y + 1][x] == '.' && x + 1 < col && board[y + 1][x + 1] == '.') {
            board[y + 1][x] = board[y + 1][x + 1] = board[y][x] = '#';
            search();
            board[y + 1][x] = board[y + 1][x + 1] = board[y][x] = '.';
        }

    }

    int getAnswer() {
        return count;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    while (tc--) {
        int row, col;
        cin >> row >> col;
        vector<vector<char>> board(row, vector<char>(col));
        string temp;
        for (int i = 0; i < row; ++i) {
            cin >> temp;
            for (int j = 0; j < col; ++j) {
                board[i][j] = temp[j];
            }
        }
        Solution s(row, col, std::move(board));
        cout << s.getAnswer() << endl;
    }
    return 0;
}