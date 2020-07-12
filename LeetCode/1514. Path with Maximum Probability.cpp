// https://leetcode.com/problems/path-with-maximum-probability/

class Solution {
public:
    // 500 ms
    // 49.2 MB
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<double> bound(n, 0.0);
        bound[start] = 1.0;
        
        int from, to;
        double prob;
        for (int i = 0; i < n; ++i) {
            bool flag = false;
            for (int j = 0; j < edges.size(); ++j) {
                from = edges[j][0];
                to = edges[j][1];
                prob = succProb[j];
                
                if (bound[from] && bound[to] < bound[from] * prob) {
                    flag = true;
                    bound[to] = bound[from] * prob;
                }
                std::swap(from, to);
                if (bound[from] && bound[to] < bound[from] * prob) {
                    flag = true;
                    bound[to] = bound[from] * prob;
                }
            }
            if (!flag) break;
        }
        return bound[end];
    }
};