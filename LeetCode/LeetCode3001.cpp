//
// Created by Luminous on 2024/12/5 14:36
//

#pragma GCC optimize(3)

#include <bits/stdc++.h>

class Solution {
public:
    const int N = 8;

    int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f) {
        if (a == e && (a != c || std::min(b, f) > d ||  d > std::max(b, f))) {
            return 1;
        }

        if (b == f && (b != d && std::min(a, e) > c && c > std::max(a, e))) {
            return 1;
        }

        int x = a - b + N - 1;
        int y = c - d + N - 1;
        int z = e - f + N - 1;
        if (y == z && (x != y && std::min(c, e) > a && a > std::max(c, e))) {
            return 1;
        }

        x = a + b;
        y = c + d;
        z = e + f;
        if (y == z && (x != y && std::min(c, e) > a && a > std::max(c, e))) {
            return 1;
        }

        return 2;
    }
};