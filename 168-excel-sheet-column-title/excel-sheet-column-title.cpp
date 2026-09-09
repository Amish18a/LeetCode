class Solution {
public:
    string convertToTitle(int columnNumber) {
    string res = "";
    while (columnNumber) {
        columnNumber--;                          // 1-indexed → 0-indexed
        res += static_cast<char>('A' + (columnNumber % 26));
        columnNumber /= 26;
    }
    reverse(res.begin(), res.end());
    return res;
}   
};