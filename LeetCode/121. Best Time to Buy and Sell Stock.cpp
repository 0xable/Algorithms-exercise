// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
// 8 ms
// 13 MB

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int result = 0;
        int buy = numeric_limits<int>::max();
        for (auto i : prices) {
            buy = std::min(i, buy);
            if (i > buy) result = std::max(result, i - buy);
        }
        return result;
    }
};