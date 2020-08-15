// https://leetcode.com/problems/letter-combinations-of-a-phone-number/
// 0 ms
// 6.6 MB

class Solution {
    string original;
    vector<string> mappingTable;
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return vector<string>();
        this -> original = digits;
        this -> mappingTable = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> result;
        string curr;
        search(0, curr, result);
        return result;
    }
    
    void search(int index, string& curr, vector<string>& result) {
        if (index == original.length()) {
            result.push_back(curr);
            return;
        }
        
        int digit = original[index] - '0';
        for (auto ch : mappingTable[digit]) {
            curr.push_back(ch);
            search(index + 1, curr, result);
            curr.pop_back();
        }
    }
};