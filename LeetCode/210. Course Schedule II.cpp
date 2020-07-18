// https://leetcode.com/problems/course-schedule-ii/

class Solution {
    vector<vector<int>> graph;
    vector<bool> visited;
    vector<bool> terminated;
    
    bool cycle;
public:
    // 44 ms
    // 14.8 MB
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        graph.assign(numCourses, vector<int>());
        visited.assign(numCourses, false);
        terminated.assign(numCourses, false);
        cycle = false;
        for (auto& vec : prerequisites) {
            graph[vec[1]].push_back(vec[0]);
        }
        
        vector<int> result;
        for (int i = 0; i < numCourses; ++i) {
            if (visited[i]) continue;
            if (cycle) break;
            search(i, result);
        }
        
        if (result.size() != numCourses || cycle) return vector<int>();
        return vector<int>(result.rbegin(), result.rend());
    }
    
    void search(int curr, vector<int>& result) {
        if (cycle) return;
        
        visited[curr] = true;
        for (auto next : graph[curr]) {
            if (visited[next]) {
                if (terminated[next]) continue;
                cycle = true;
                return;
            }
            
            search(next, result);
        }
        terminated[curr] = true;
        result.push_back(curr);
        return;
    }
};