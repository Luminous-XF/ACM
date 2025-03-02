//
// Created by Luminous on 2025/1/6 16:19
//

#pragma GCC optimize(3)

#include <bits/stdc++.h>

#define endl "\n"


class Solution {
public:
    std::string convertDateToBinary(std::string date) {
        int yy = std::stoi(date.substr(0, 4));
        int mm = std::stoi(date.substr(5, 2));
        int dd = std::stoi(date.substr(8, 2));
        std::string YY = toBinary(yy);
        std::string MM = toBinary(mm);
        std::string DD = toBinary(dd);
        return YY + "-" + MM + "-" + DD;
    }

    std::string toBinary(int k) {
        std::string res;
        while (k > 0) {
            res.push_back(char(k % 2 + '0'));
            k >>=1;
        }
        std::reverse(res.begin(), res.end());
        return res;
    }
};