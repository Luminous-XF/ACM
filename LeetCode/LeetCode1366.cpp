//
// Created by Luminous on 2024/12/29 16:49
//

#pragma GCC optimize(3)

#include <bits/stdc++.h>

class Solution {
public:
    std::string rankTeams(std::vector<std::string> &votes) {
        const int n = (int) votes.size();
        const int m = (int) votes[0].size();

        std::unordered_map<char, std::vector<int>> book;
        for (char c : votes[0]) {
            book[c].resize(m);
        }

        for (auto& s : votes) {
            for (int i = 0; i < m; i++) {
                book[s[i]][i]++;
            }
        }

        using PAIR = std::pair<char, std::vector<int>>;
        std::vector<PAIR> v(book.begin(), book.end());
        std::sort(v.begin(), v.end(), [](const PAIR& a, const PAIR& b) {
           if (a.second != b.second) return a.second > b.second;
           return a.first < b.first;
        });

        std::string ans;
        for (auto& [c, _] : v) {
            ans.push_back(c);
        }

        return ans;
    }
};