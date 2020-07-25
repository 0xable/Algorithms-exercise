// https://leetcode.com/problems/sum-of-two-integers/

class Solution {
public:
    // 0 ms
    // 5.9 MB
    int getSum(int a, int b) {
        int result = a ^ b;
        int carry = a & b;
        int negativeFlag = 1 << 31;
        
        while (carry) {
            if (carry & negativeFlag) {
                carry ^= negativeFlag;
            }

            int temp = carry << 1;
            carry = result & temp;
            result ^= temp;
        }
        return result;
    }
};