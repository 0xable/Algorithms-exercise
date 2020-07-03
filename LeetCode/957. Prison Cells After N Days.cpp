// https://leetcode.com/problems/prison-cells-after-n-days/
// 8 ms

class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        vector<vector<int>> table;
        map<int, int> indexMapping;
        
        int i = 0;
        vector<int> prev = cells;
        vector<int> curr(8, 0);
        while (!indexMapping.count(conversion(curr)) && N--) {
            indexMapping[conversion(prev)] = i++;
            table.push_back(prev);
			
            curr[0] = curr[7] = 0;
            for (int i = 1; i < 7; ++i) {
                if (prev[i - 1] == prev[i + 1]) {
                    curr[i] = 1;
                } else {
                    curr[i] = 0;
                }
            }
			
            prev = curr;
        }
        
        if (!indexMapping.count(conversion(curr)))
            return curr;
        
        int cycleStart = indexMapping[conversion(curr)];
        int cycleLength = table.size() - cycleStart;
        N %= cycleLength;
        return table[cycleStart + N];
    }
    
    int conversion(vector<int>& cells) {
        int result = 0;
        for (int i = 0; i < 8; ++i) {
            result *= 2;
            result += cells[i];
        }
        return result;
    }
};