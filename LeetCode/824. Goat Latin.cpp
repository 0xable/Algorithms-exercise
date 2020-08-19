// https://leetcode.com/problems/goat-latin/
// 0 ms
// 6.4 MB

class Solution {
    bool isVowel(char ch) {
        ch = tolower(ch);
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') return true;
        return false;
    }
    
public:
    string toGoatLatin(string S) {
        string result;
        int wordCount = 1;
        int i = 0;
        
        while (i < S.length()) {
            if (isVowel(S[i])) {
                while (i < S.length() && S[i] != ' ') {
                    result.push_back(S[i]);
                    ++i;
                }
                
            } else {
                char last = S[i];
                ++i;
                while (i < S.length() && S[i] != ' ') {
                    result.push_back(S[i]);
                    ++i;
                }
                result.push_back(last);
            }
            result.push_back('m');
            result.push_back('a');
            for (int j = 0; j < wordCount; ++j) {
                result.push_back('a');
            }
            result.push_back(' ');
            
            ++wordCount;
            ++i;
        }
        result.pop_back();
        return result;
    }
};