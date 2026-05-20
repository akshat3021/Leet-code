#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int divide(int dividend, int divisor) {

        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;

        bool negative = (dividend < 0) ^ (divisor < 0);

        // Convert to positive long long
        long long dvd = labs((long long)dividend);
        long long dvs = labs((long long)divisor);

        long long ans = 0;

        for (int i = 31; i >= 0; i--) {

            if ((dvd >> i) >= dvs) {

                ans += (1LL << i);

                dvd -= (dvs << i);
            }
        }

        return negative ? -ans : ans;
    }
};