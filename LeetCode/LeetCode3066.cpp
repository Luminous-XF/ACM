//
// Created by Luminous on 2025/1/15 16:11
//

#pragma GCC optimize(3)

#include <bits/stdc++.h>

class Solution {
public:
    int minOperations(std::vector<int>& nums, int k) {
        std::priority_queue<long long, std::vector<long long>, std::greater<>> q(nums.begin(), nums.end());

        int ans = 0;
        while (q.top() < k && q.size() >= 2) {
            ans++;
            long long x = q.top(); q.pop();
            long long y = q.top(); q.pop();
            q.push(x + x + y);
        }

        return ans;
    }
};