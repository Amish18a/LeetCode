class Solution {
public:
    unsigned long long C2nN(int n){
        unsigned long long res = 1;
        for(int i = 1; i<=n; ++i) res = res*(n+i)/i;
        return res;
    }
    int numTrees(int n) {
        return C2nN(n)/(n+1);
    }
};