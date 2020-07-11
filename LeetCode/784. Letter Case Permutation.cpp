// https://leetcode.com/problems/letter-case-permutation/

class Solution {
    vector<int> letterIndex;
public:
    // 8 ms
    // 9.4 MB
    vector<string> letterCasePermutation(string S) {
        for (int i = 0; i < S.size(); ++i) {
            if (isdigit(S[i])) continue;
            
            letterIndex.push_back(i);
            if (islower(S[i])) {
                S[i] -= 0x20;
            }
        }
        
        vector<string> result;
        search(0, S, result);
        return result;
    }
    
    void search(int index, string& curr, vector<string>& result) {
        if (index == letterIndex.size()) {
            result.push_back(curr);
            return;
        }
        
        int currLetterIndex = letterIndex[index];
        curr[currLetterIndex] += 0x20;
        search(index + 1, curr, result);
        curr[currLetterIndex] -= 0x20;
        search(index + 1, curr, result);
        return;
    }
};