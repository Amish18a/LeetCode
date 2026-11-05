class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int i = 0,j = 0,x = arr1.size();
        for(i;i<arr1.size();i++){
            for(j=0;j<arr2.size();j++){
                if(abs(arr1[i] - arr2[j])<=d) {
                    x--;
                    break;
                }
            }
        }
        return x;
    }
};