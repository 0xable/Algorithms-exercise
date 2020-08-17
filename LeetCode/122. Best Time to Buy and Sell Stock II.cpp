// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
// 12 ms
// 13.1 MB

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        int result = 0;
        int prev = prices[0];
        int buy = prices[0];
        for (auto x : prices) {
            if (prev > x) {
                result += prev - buy;
                buy = x;
            }
            prev = x;
        }
        if (buy < prices.back()) result += prices.back() - buy;
        return result;
    }
};