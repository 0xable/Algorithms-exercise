// https://leetcode.com/problems/stone-game-iv/

class Solution {
    vector<int> cache;
public:
    // 108 ms
    // 12.1 MB
    bool winnerSquareGame(int n) {
        cache.assign(n + 1, 0);
        return search(n);
    }
    
    bool search(int remain) {
        if (remain == 0) return false;
        if (cache[remain] != 0) {
            if (cache[remain] == 1) return true;
            return false;
        }

        int step = 1;
        while (step * step <= remain) {
            if (!search(remain - step * step)) {
                cache[remain] = 1;
                return true;
            }
            ++step;
        }
        cache[remain] = -1;
        return false;
    }
};