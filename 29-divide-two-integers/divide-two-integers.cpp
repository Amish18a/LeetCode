class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == 1) return dividend;
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;

        bool positive = (dividend > 0) == (divisor > 0);

        // Work in negative to avoid abs(INT_MIN) overflow
        long a = dividend > 0 ? -(long)dividend : dividend;
        long b = divisor > 0 ? -(long)divisor : divisor;

        long quotient = 0;
        while (a <= b) {
            long curB = b, curQ = 1;
            while (a <= (curB << 1)) {
                curB <<= 1;
                curQ <<= 1;
            }
            a -= curB;
            quotient += curQ;
        }

        return positive ? (int)quotient : (int)(-quotient);
    }
};   