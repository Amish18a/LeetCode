class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if (n<2) return 0;

        int mn = *min_element(nums.begin(),nums.end());
        int mx = *max_element(nums.begin(),nums.end());
        if (mx == mn) return 0;

        int size = max(1,(mx-mn)/(n-1));
        int buckets = (mx - mn)/size + 1;

        vector<int> bmin(buckets,INT_MAX),bmax(buckets,-1);

        for(int x: nums){
            int idx = (x - mn)/size;
            bmin[idx] = min(bmin[idx],x);
            bmax[idx] = max(bmax[idx],x);
        }

        int ans = 0, prevMax = mn;
        for(int i=0;i<buckets;i++){
            if (bmin[i] == INT_MAX) continue;
            ans = max(ans,bmin[i] - prevMax);
            prevMax = bmax[i];
        }

        return ans;
    }
};