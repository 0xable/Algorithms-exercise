// https://leetcode.com/problems/all-paths-from-source-to-target/

class Solution {
    vector<int> visited;
public:
    // 16 ms
    // 10.5 MB
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        visited.assign(graph.size(), false);
        vector<vector<int>> result;
        vector<int> curr = {0};
        
        search(0, graph, curr, result);
        return result;
    }
    
    void search(int curr, vector<vector<int>>& graph, vector<int>& currPath, vector<vector<int>>& result) {
        if (curr == graph.size() - 1) {
            result.push_back(currPath);
            return;
        }
        
        int n = graph.size();
        for (auto i : graph[curr]) {
            if (!visited[i]) {
                currPath.push_back(i);
                visited[i] = true;
                search(i, graph, currPath, result);
                currPath.pop_back();
                visited[i] = false;
            }
        }
    }
};