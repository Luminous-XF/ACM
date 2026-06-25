//
// Created by Luminous on 2026/3/6 23:49
//


#pragma GCC optimize(3)

#include <bits/stdc++.h>

class Solution {
public:
    bool checkOnesSegment(std::string s) {
        return s.find("01") == std::string::npos;
    }
};