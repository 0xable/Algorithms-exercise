// https://leetcode.com/problems/maximum-product-of-word-lengths/

class Solution {
public:
    // 88 ms
    // 16.2 MB
    int maxProduct(vector<string>& words) {
        vector<int> letterSet(words.size());
        vector<int> wordLength(words.size());
        for (int i = 0; i < words.size(); ++i) {
            int curr = 0;
            for (auto ch : words[i]) {
                curr |= (1 << (ch - 'a'));
            }
            letterSet[i] = curr;
            wordLength[i] = words[i].size();
        }
        
        int product = 0;
        for (int i = 0; i < letterSet.size(); ++i) {
            for (int j = i + 1; j < letterSet.size(); ++j) {
                if ((letterSet[i] & letterSet[j]) == 0) {
                    product = std::max(product, wordLength[i] * wordLength[j]);
                }
            }
        }
        return product;
    }
};