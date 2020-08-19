// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/
// 4 ms
// 11.5 MB

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) return 0;
        
        vector<int> buy(prices.size());
        vector<int> sell(prices.size());
        vector<int> coolDown(prices.size());
        buy[0] = -prices[0];
        sell[0] = 0;
        coolDown[0] = 0;

        for (int i = 1; i < prices.size(); ++i) {
            buy[i] = std::max(buy[i - 1], coolDown[i - 1] - prices[i]);
            sell[i] = buy[i - 1] + prices[i];
            coolDown[i] = std::max(coolDown[i - 1], sell[i - 1]);
        }
        return std::max(sell[prices.size() - 1], coolDown[prices.size() - 1]);
    }
};