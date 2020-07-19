// https://leetcode.com/problems/add-binary/

class Solution {
public:
    // 4 ms
    // 6.6 MB
    string addBinary(string a, string b) {
        int carry = 0;
        auto iterA = a.rbegin();
        auto iterB = b.rbegin();
        string result;
        while (iterA != a.rend() && iterB != b.rend()) {
            int aDigit = (*iterA) - '0';
            int bDigit = (*iterB) - '0';
            int currDigit = aDigit + bDigit + carry;
            carry = currDigit > 1 ? 1 : 0;
            currDigit %= 2;
            result.push_back(currDigit + '0');
            ++iterA;
            ++iterB;
        }
        
        while (iterA != a.rend()) {
            if (carry) {
                if ((*iterA) - '0') {
                    carry = 1;
                    result.push_back('0');
                } else {
                    carry = 0;
                    result.push_back('1');
                }
            } else {
                result.push_back(*iterA);
            }
            ++iterA;
        }
        
        while (iterB != b.rend()) {
            if (carry) {
                if ((*iterB) - '0') {
                    carry = 1;
                    result.push_back('0');
                } else {
                    carry = 0;
                    result.push_back('1');
                }
            } else {
                result.push_back(*iterB);
            }
            ++iterB;
        }
        
        if (carry) result.push_back('1');
        return string(result.rbegin(), result.rend());
    }
};