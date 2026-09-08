class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0")
            return "0";

        int m = num1.size(), n = num2.size();
        vector<int> arr(m + n, 0);  // product has at most m+n digits

        // Multiply each digit pair, accumulate at position i+j+1
        for (int i = m - 1; i >= 0; --i) {
            int a = num1[i] - '0';
            for (int j = n - 1; j >= 0; --j) {
                int b = num2[j] - '0';
                arr[i + j + 1] += a * b;
            }
        }

        // Handle carries right to left
        for (int i = arr.size() - 1; i > 0; --i) {
            arr[i - 1] += arr[i] / 10;
            arr[i] %= 10;
        }

        // Build result, skipping leading zero
        int start = arr[0] ? 0 : 1;
        string ans;
        for (int i = start; i < arr.size(); ++i)
            ans += '0' + arr[i];
        return ans;
    }
};   