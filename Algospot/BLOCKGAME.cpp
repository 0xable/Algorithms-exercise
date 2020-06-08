// https://algospot.com/judge/problem/read/BLOCKGAME
// 구종만, 알고리즘 문제 해결 전략, 인사이트, 2012, p344 - 348 참조
// 448 ms

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
    vector<char> cache;
    vector<int> moves;
public:
    Solution() {
        cache.assign(1 << 25, 0);
        precalc();
    }

    inline int cell(int y, int x) {
        return 1 << (y * 5 + x);
    }

    void precalc() {
        // 세 칸짜리 블록들을 계산한다.
        for (int y = 0; y < 4; ++y) {
            for (int x = 0; x < 4; ++x) {
                vector<int> cells;
                for (int dy = 0; dy < 2; ++dy) {
                    for (int dx = 0; dx < 2; ++dx) {
                        cells.push_back(cell(y + dy, x + dx));
                    }
                }
                int square = cells[0] + cells[1] + cells[2] + cells[3];
                for (int i = 0; i < 4; ++i) {
                    moves.push_back(square - cells[i]);
                }
            }
        }

        // 두 칸짜리 블록들을 계산한다.
        for (int i = 0; i < 5; ++i) {
            for (int j = 0; j < 4; ++j) {
                moves.push_back(cell(i, j) + cell(i, j + 1));
                moves.push_back(cell(j, i) + cell(j + 1, i));
            }
        }
    }

    char search(vector<vector<bool>>& b) {
        int board = 0;
        for (int i = 0; i < 5; ++i) {
            for (int j = 0; j < 5; ++j) {
                if (!b[j][i]) continue;
                board += cell(j, i);
            }
        }
        return search(board);
    }

    char search(int board) {
        if (cache[board] != 0) {
            return cache[board];
        }

        int result = -1;
        for (int i = 0; i < moves.size(); ++i) {
            if ((moves[i] & board) != 0) continue;
            if (search(board | moves[i]) == -1) {
                result = 1;
                break;
            }
        }
        return cache[board] = result;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    Solution s;
    while (tc--) {
        vector<vector<bool>> board(5, vector<bool>(5, false));
        string input;
        for (int i = 0; i < 5; ++i) {
            cin >> input;
            for (int j = 0; j < 5; ++j) {
                board[i][j] = input[j] == '#' ? true : false;
            }
        }
        if (s.search(board) == 1) {
            cout << "WINNING" << endl;
        } else {
            cout << "LOSING" << endl;
        }
    }
    return 0;
}