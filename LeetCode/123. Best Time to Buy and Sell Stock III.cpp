// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/
// 12 ms
// 13.4 MB

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) return 0;
        vector<int> leftProfit(prices.size());
        vector<int> rightProfit(prices.size());
        
        int leftBuy = numeric_limits<int>::max();
        int rightSell = 0;
        int leftResult = 0, rightResult = 0;
        int right;
        for (int i = 0; i < prices.size(); ++i) {
            leftBuy = std::min(leftBuy, prices[i]);
            leftResult = std::max(leftResult, prices[i] - leftBuy);
            leftProfit[i] = leftResult;
            
            right = prices.size() - i - 1;
            rightSell = std::max(rightSell, prices[right]);
            rightResult = std::max(rightResult, rightSell - prices[right]);
            rightProfit[right] = rightResult;
        }
        
        
        int result = std::max(leftProfit[prices.size() - 1], rightProfit[0]);
        for (int i = 1; i < prices.size() - 1; ++i) {
            result = std::max(result, leftProfit[i] + rightProfit[i + 1]);
        }
        return result;
    }
};