//
// Created by Luminous on 2024/12/3 17:39
//

#pragma GCC optimize(3)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkTwoChessboards(string coordinate1, string coordinate2) {
        int x1 = coordinate1[1] - '0', y1 = coordinate1[0] - 'a';
        int color1 = (y1 & 1) ^ (x1 & 1);
        int x2 = coordinate2[1] - '0', y2 = coordinate2[0] - 'a';
        int color2 = (y2 & 1) ^ (x2 & 1);
        return color1 == color2;
    }
};