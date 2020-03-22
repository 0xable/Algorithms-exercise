// https://cses.fi/problemset/task/1624

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
 
using namespace std;
 
class Chessboard {
private:
    vector<vector<char>> board;
    vector<int> diag1;
    vector<int> diag2;
    vector<int> rows;
    int n;
    int answer;
 
public:
    Chessboard() {
        n = 8;
        answer = 0;
        board.reserve(8);
        for (int i = 0; i < 8; i++) {
            board[i] = vector<char>(8);
        }
        string input;
        for (int i = 0; i < 8; ++i) {
            getline(cin, input);
            for (int j = 0; j < 8; ++j) {
                board[i][j] = input[j];
            }
        }
 
        diag1.reserve(64);
        diag2.reserve(64);
 
        for (int i = 0; i < 8; ++i) {
            int j = i;
            while (j % 8 != 7) {
                diag1[j] = i;
                j += 9;
            }
            diag1[j] = i;
        }
        for (int i = 8; i <= 56; i += 8) {
            int j = i;
            while (j < 64) {
                diag1[j] = i;
                j += 9;
            }
        }
 
        for (int i = 0; i < 8; ++i) {
            int j = i;
            while (j % 8 != 0) {
                diag2[j] = i;
                j += 7;
            }
            diag2[j] = i;
        }
        for (int i = 15; i <= 63; i += 8) {
            int j = i;
            while (j < 64) {
                diag2[j] = i;
                j += 7;
            }
        }
    }
 
    bool isValid(int row, int col) {
        if (board[row][col] == '*') {
            return false;
        }
        for (auto cols : rows) {
            if (cols == col) {
                return false;
            }
        }
        for (int i = 0; i < row; ++i) {
            if (diag1[i * 8 + rows[i]] == diag1[row * 8 + col] || diag2[i * 8 + rows[i]] == diag2[row * 8 + col]) {
                return false;
            }
        }
        return true;
    }
 
    void search(int row) {
        if (row == 8) {
            ++answer;
            return;
        }
 
        for (int col = 0; col < 8; ++col) {
            if (isValid(row, col)) {
                rows.push_back(col);
                search(row + 1);
                rows.pop_back();
            }
        }
    }
 
    void getAnswer() {
        cout << answer << endl;
    }
};
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    Chessboard chessboard;
    chessboard.search(0);
    chessboard.getAnswer();
    return 0;
}