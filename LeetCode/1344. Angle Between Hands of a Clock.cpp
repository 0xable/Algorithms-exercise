// https://leetcode.com/problems/angle-between-hands-of-a-clock/

class Solution {
public:
    // 0 ms
    // 6.1 MB
    double angleClock(int hour, int minutes) {
        double m = minutes * 6;
        double h = (hour % 12) * 30 + minutes / 60.0 * 30;
        double angle1 = abs(h - m);
        double angle2 = 360 - angle1;
        return std::min(angle1, angle2);
    }
};