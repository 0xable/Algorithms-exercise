// https://algospot.com/judge/problem/read/FENCE

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int search(vector<int>& height, int start, int end) {
    if (start == end) {
        return height[start];
    }
    int mid = (start + end) / 2;
    int backward = mid;
    int forward = mid + 1;
    
    int max = -1;
    int area = 0;
    int minHeight = 987654321;
    int width = 1;
    while (start <= backward && forward <= end) {
        if (height[backward] <= height[forward]) {
            minHeight = std::min(minHeight, height[forward]);
            ++forward;
        } else {
            minHeight = std::min(minHeight, height[backward]);
            --backward;
        }
        area = width * minHeight;
        if (max < area) max = area;
        ++width;
    }

    while (start <= backward) {
        minHeight = std::min(minHeight, height[backward]);
        area = width * minHeight;
        if (max < area) max = area;
        ++width;
        --backward;
    }

    while (forward <= end) {
        minHeight = std::min(minHeight, height[forward]);
        area = width * minHeight;
        if (max < area) max = area;
        ++width;
        ++forward;
    }

    int left = search(height, start, mid);
    int right = search(height, mid + 1, end);
    return std::max({left, right, max});
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<int> height(n);
        for (int i = 0; i < n; ++i) {
            cin >> height[i];
        }
        cout << search(height, 0, n - 1) << endl;
    }
    return 0;
}