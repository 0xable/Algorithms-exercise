// https://leetcode.com/problems/compare-version-numbers/
// 0 ms
// 6.5 MB

class Solution {
public:
    int compareVersion(string version1, string version2) {
        stringstream ss1(version1);
        stringstream ss2(version2);
        vector<int> ver1;
        vector<int> ver2;
        
        string temp;
        while (std::getline(ss1, temp, '.')) {
            ver1.push_back(std::stoi(temp));
        }
        while (std::getline(ss2, temp, '.')) {
            ver2.push_back(std::stoi(temp));
        }
        
        int i = 0;
        int minSize = std::min(ver1.size(), ver2.size());
        while (i < minSize) {
            if (ver1[i] != ver2[i]) {
                return ver1[i] > ver2[i] ? 1 : -1;
            }
            ++i;
        }
        
        if (ver1.size() == ver2.size()) return 0;
        if (ver1.size() > ver2.size()) {
            while (i < ver1.size()) {
                if (ver1[i]) return 1;
                ++i;
            }
            return 0;
        } else {
            while (i < ver2.size()) {
                if (ver2[i]) return -1;
                ++i;
            }
            return 0;
        }
    }
};