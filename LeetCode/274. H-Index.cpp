// https://leetcode.com/problems/h-index/
// 8 ms
// 8.6 MB

class Solution {
public:
    int hIndex(vector<int>& citations) {
        std::sort(citations.begin(), citations.end());
        int n = citations.size();
        int result = 0;
        int i = 0;
        while (i < n) {
            result = std::max(result, std::min(n - i, citations[i]));
            ++i;
            while (i < n && citations[i] == citations[i - 1]) {
                ++i;
            }
        }
        return result;
    }
};