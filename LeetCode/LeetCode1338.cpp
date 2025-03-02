//
// Created by Luminous on 2024/12/17 17:07
//

#pragma GCC optimize(3)

#include <bits/stdc++.h>

class Solution {
public:
    int minSetSize(std::vector<int>& arr) {
        std::unordered_map<int, int> map;
        for (int x : arr) {
            map[x]++;
        }

        std::vector<int> v;
        for (auto &[key, value] : map) {
            v.push_back(value);
        }

        std::sort(v.begin(), v.end(), std::greater<>());
        const int n = (int) arr.size();
        int sum = 0;
        for (int i = 0; i < v.size(); i++) {
            sum += v[i];
            if (sum >= n / 2) {
                return i + 1;
            }
        }

        return -1;
    }
};