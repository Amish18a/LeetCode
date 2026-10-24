class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lo = 0, hi = nums.size() - 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] == target) return mid;

            if (nums[lo] <= nums[mid]) {              // left half [lo..mid] is sorted
                if (nums[lo] <= target && target < nums[mid])
                    hi = mid - 1;                     // target is in the sorted left half
                else
                    lo = mid + 1;
            } else {                                  // right half [mid..hi] is sorted
                if (nums[mid] < target && target <= nums[hi])
                    lo = mid + 1;                     // target is in the sorted right half
                else
                    hi = mid - 1;
            }
        }
        return -1;
    }
};