//
// Created by Luminous on 2024/12/12 18:01
//

#pragma GCC optimize(3)

#include <bits/stdc++.h>

class Solution {
public:
    long long maxSpending(std::vector<std::vector<int>>& values) {
        const int m = (int) values.size();
        const int n = (int) values[0].size();

        std::priority_queue<std::array<int, 2>, std::vector<std::array<int, 2>>, std::greater<>> q;
        for (int i = 0; i < m; i++) {
            q.push({values[i].back(), i});
        }

        long long ans = 0;
        for (int d = 1; d <= m * n; d++) {
            auto [v, i] = q.top();
            q.pop();
            ans += (long long) d * v;
            values[i].pop_back();
            if (values[i].empty()) continue;
            q.push({values[i].back(), i});
        }

        return ans;
    }
};