// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/

class Solution {
public:
    // CAUTION. It's so dirty.
    // 8 ms
    // 12.3 MB
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        int mid;
        
        while (left <= right) {
            mid = (left + right) / 2;
            
            if (nums[left] < nums[mid]) {
                if (nums[mid] <= nums[right]) {
                    break;
                } else {
                    left = mid + 1;
                }
                
            } else if (nums[left] == nums[mid]) {
                if (nums[mid] < nums[right]) {
                    break;
                } else if (nums[mid] > nums[right]) {
                    left = mid + 1;                
                } else if (nums[mid] == nums[right]) {
                    while (left < mid && nums[left] == nums[mid]) {
                        ++left;
                    }
                    if (left == mid) {
                        while (left < right && nums[left] == nums[right]) {
                            ++left;
                        }
                        if (left == right || nums[left] < nums[right]) {
                            break;
                        } else if (nums[left] > nums[right]) {
                            continue;
                        }
                    } else if (nums[left] < nums[mid]) {
                        break;
                    } else if (nums[left] > nums[mid]) {
                        continue;
                    }
                }
                
            } else {
                right = mid;
            }
        }
        return nums[left];
    }
};