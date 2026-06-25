//
// Created by Luminous on 2026/3/11 11:18
//


#pragma GCC optimize(3)

#include <bits/stdc++.h>

class Solution {
public:
    int minArrivalsToDiscard(std::vector<int>& arrivals, int w, int m) {
        const int n = (int) arrivals.size();

        std::unordered_map<int, int> book;
        std::vector<bool> vis(n, false);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (book[arrivals[i]] < m) {
                book[arrivals[i]]++;
            } else {
                vis[i] = true;
                ans++;
            }

            int j = i - w + 1;
            if (j >= 0 && !vis[j]) {
                book[arrivals[j]]--;
            }
        }

        return ans;
    }
};