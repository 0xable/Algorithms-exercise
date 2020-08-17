// https://leetcode.com/problems/distribute-candies-to-people/
// 0 ms
// 6.3 MB

class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> result(num_people, 0);
        int curr = 1;
        int i = 0;
        while (candies > 0) {
            result[i] += std::min(curr, candies);
            candies -= curr;
            ++curr;
            ++i;
            if (i == num_people)
                i = 0;
        }
        return result;
    }
};