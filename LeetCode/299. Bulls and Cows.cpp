// https://leetcode.com/problems/bulls-and-cows/
// 4 ms
// 6.6 MB

class Solution {
public:
    string getHint(string secret, string guess) {
        vector<int> secretNum(10, 0);
        vector<int> guessNum(10, 0);
        int bull = 0, cow = 0;
        
        for (int i = 0; i < secret.length(); ++i) {
            if (secret[i] == guess[i]) {
                ++bull;
            } else {
                secretNum[secret[i] - '0'] += 1;
                guessNum[guess[i] - '0'] += 1;
            }
        }
        for (int i = 0; i < 10; ++i) {
            cow += std::min(secretNum[i], guessNum[i]);
        }
        return std::to_string(bull) + "A" + std::to_string(cow) + "B";
    }
};