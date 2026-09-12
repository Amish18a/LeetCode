class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size()-1;
        if (n==0) return 0;
        if (nums[n]>nums[n-1]) return n;
        for(int i=n-1;i>=1;i--){
            if (nums[i]>nums[i-1] && nums[i]>nums[i+1]) return i;
        }
        return 0;
    }
};