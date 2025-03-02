//
// Created by Luminous on 2024/12/9 17:47
//

#pragma GCC optimize(3)

#include <bits/stdc++.h>

class Solution {
public:
    bool squareIsWhite(std::string coordinates) {
        int x = coordinates[1] - '1';
        int y = coordinates[0] - 'a';
        return ((x & 1) ^ (y & 1)) == 1;
    }
};