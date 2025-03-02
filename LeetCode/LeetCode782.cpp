//
// Created by Luminous on 2024/12/8 22:03
//

#pragma GCC optimize(3)

#include <bits/stdc++.h>

class Solution {
public:
    int movesToChessboard(std::vector<std::vector<int>> &board) {
        std::map<std::string, int> map;
        for (auto &v: board) {
            std::string s;
            for (auto c: v) {
                s.push_back((char) (c + '0'));
            }
            map[s]++;
        }

        if (map.size() != 2) return -1;

        auto it1 = map.begin();
        auto it2 = map.rbegin();

        if (std::abs(it1->second - it2->second) > 1) return -1;

        std::string s1 = it1->first;
        int cnt01 = std::count(s1.begin(), s1.end(), '0');
        int cnt11 = std::count(s1.begin(), s1.end(), '1');
        std::string s2 = it2->first;
        int cnt02 = std::count(s2.begin(), s2.end(), '0');
        int cnt12 = std::count(s2.begin(), s2.end(), '1');

        if (std::abs(cnt01 - cnt11) > 1) return -1;
        if (std::abs(cnt02 - cnt12) > 1) return -1;
        if (cnt01 != cnt11 && cnt01 - cnt11 == cnt02 - cnt12) return -1;

        const int n = (int) board.size();
        int cnt[2][3] = {0};
        for (int i = 0; i < n; i += 2) {
            if (board[0][i] == 0) cnt[0][2]++;
            if (board[i][0] == 0) cnt[1][2]++;
        }

        for (int i = 0; i < n; i++) {
            if (board[0][i] == 0) cnt[0][0]++;
            else cnt[0][1]++;
            if (board[i][0] == 0) cnt[1][0]++;
            else cnt[1][1]++;
        }

        if (n % 2 == 0) {
            int ans1 = std::min(cnt[0][2], n / 2 - cnt[0][2]);
            int ans2 = std::min(cnt[1][2], n / 2 - cnt[1][2]);
            return ans1 + ans2;
        } else {
            int ans1 = (cnt[0][0] > cnt[0][1] ? (n + 1) / 2 - cnt[0][2] : cnt[0][2]);
            int ans2 = (cnt[1][0] > cnt[1][1] ? (n + 1) / 2 - cnt[1][2] : cnt[1][2]);
            return ans1 + ans2;
        }
    }
};