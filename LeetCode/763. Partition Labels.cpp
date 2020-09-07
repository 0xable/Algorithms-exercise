// https://leetcode.com/problems/partition-labels/
// 4 ms
// 6.6 MB

class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> lastIndex(26, 0);
        for (int i = 0; i < S.length(); ++i) {
            lastIndex[S[i] - 'a'] = i;
        }
        
        vector<int> result;
        int i = 0;
        int lastPartition = -1;
        int currentStep;
        
        while (i < S.length()) {
            currentStep = lastIndex[S[i] - 'a'];
            while (i <= currentStep) {
                currentStep = std::max(currentStep, lastIndex[S[i] - 'a']);
                ++i;
            }
            result.push_back(currentStep - lastPartition);
            lastPartition = currentStep;
        }
        return result;
    }
};