// https://leetcode.com/problems/generate-parentheses/
// 4 ms
// 11.5 MB

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string curr;
        search(n, n, curr, result);
        return result;
    }
    
    void search(int open, int close, string& curr, vector<string>& result) {
        if (open == 0 && close == 0) {
            result.push_back(curr);
            return;
        }
        if (open > 0) {
            curr.push_back('(');
            search(open - 1, close, curr, result);
            curr.pop_back();
        }
        if (open < close) {
            curr.push_back(')');
            search(open, close - 1, curr, result);
            curr.pop_back();
        }
    }
};