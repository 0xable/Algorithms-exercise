// https://leetcode.com/problems/robot-bounded-in-circle/
// 0 ms
// 6.1 MB

class Solution {
public:
    bool isRobotBounded(string instructions) {
        int direction = 0;
        int x = 0, y = 0;
        for (int i = 0; i < 4; ++i) {
            for (auto& action : instructions) {
                operate(action, direction, x, y);
            }
        }
        if (x == 0 && y == 0 && direction == 0) return true;
        return false;
    }
    
    void operate(char action, int& direction, int& x, int& y) {
        if (action == 'G') {
            if (direction == 0) {
                ++y;
            } else if (direction == 1) {
                ++x;
            } else if (direction == 2) {
                --y;
            } else {
                --x;
            }
        } else if (action == 'L') {
            direction = (direction - 1 + 4) % 4;
        } else {
            direction = (direction + 1) % 4;
        }
    }
};