// https://leetcode.com/problems/plus-one/

class Solution {
public:
    // 4 ms
    // 9.1 MB
    vector<int> plusOne(vector<int>& digits) {
        int length = digits.size();
        vector<int> result(length);
        int carry = 1;
        int digit;
        for (int i = 0; i < length; ++i) {
            digit = digits[length - i - 1] + carry;
            result[i] = digit % 10;
            carry = digit / 10;
        }
        
        if (carry) result.push_back(1);
        std::reverse(result.begin(), result.end());
        return result;
    }
};