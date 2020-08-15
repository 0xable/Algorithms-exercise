// https://leetcode.com/problems/non-overlapping-intervals/
// 32 ms
// 10.2 MB

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });
        
        int result = 0;
        int lastEnd = numeric_limits<int>::min();
        for (int i = 0; i < intervals.size(); ++i) {
            if (lastEnd > intervals[i][0]) {
                ++result;
            } else {
                lastEnd = intervals[i][1];
            }
        }
        return result;
    }
};