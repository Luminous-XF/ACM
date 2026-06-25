//
// Created by Luminous on 2026/3/14 3:30
//


#pragma GCC optimize(3)

#include <bits/stdc++.h>

class Solution {
public:
    int totalFruit(std::vector<int>& fruits) {
        const int n = (int) fruits.size();

        int ans = 0, cnt = 0;
        std::unordered_map<int, int> book;
        for (int i = 0, j = 0; i < n; i++) {
            book[fruits[i]]++;
            cnt++;
            while (book.size() > 2) {
                auto it = book.find(fruits[j]);
                it->second--;
                cnt--;
                if (it->second == 0) {
                    book.erase(it);
                }
                j++;
            }

            ans = std::max(ans, cnt);
        }

        return ans;
    }
};