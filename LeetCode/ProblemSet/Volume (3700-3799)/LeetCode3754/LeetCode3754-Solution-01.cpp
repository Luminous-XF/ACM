#include <bits/stdc++.h>

class Solution {
public:
    long long sumAndMultiply(int n) {
        if (n == 0) {
            return 0;
        }

        long long x = 0, sum = 0, k = 1;
        while (n > 0) {
            int v = n % 10;
            n /= 10;
            if (v == 0) {
                continue;
            }

            sum += v;
            x += v * k;
            k *= 10;
        }

        return x * sum;
    }
};