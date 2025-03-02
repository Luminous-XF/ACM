//
// Created by Luminous on 2025/3/2 19:31
//

#pragma GCC optimize(3)

#include <bits/stdc++.h>

class Solution {
public:

        const std::string MAP[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    std::vector<std::string> letterCombinations(std::string digits) {
        std::vector<std::string> ans;
        if (digits.length() == 0) {
            return ans;
        }

        std::string s;
        dfs(0, s, digits, ans);

        return ans;
    }

    void dfs(int step, std::string &s, std::string &digits, std::vector<std::string> &ans) {
        if (step == digits.length()) {
            ans.push_back(s);
            return;
        }

        const int num = digits[step] - '0';
        for (char c: MAP[num]) {
            s.push_back(c);
            dfs(step + 1, s, digits, ans);
            s.pop_back();
        }
    }
};