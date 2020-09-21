// https://leetcode.com/problems/car-pooling/
// 24 ms
// 9.6 MB

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        std::sort(trips.begin(), trips.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });
        int passenger = 0;
        priority_queue<pair<int, int>> boarding;
        
        for (auto& trip : trips) {
            if (passenger + trip[0] > capacity) {
                while (!boarding.empty()) {
                    auto& passed = boarding.top();
                    if (-passed.first > trip[1]) break;
                    passenger -= passed.second;
                    boarding.pop();
                }
                if (passenger + trip[0] > capacity) return false;
            }
            passenger += trip[0];
            boarding.push(make_pair(-trip[2], trip[0]));
        }
        return true;
    }
};