#include <bits/stdc++.h>

class Solution {
public:
    std::vector<bool> pathExistenceQueries(int n, std::vector<int>& nums, int maxDiff, std::vector<std::vector<int>>& queries) {
        std::vector<int> pre(n);

        pre[0] = 0;
        for (int i = 1; i < n; i++) {
            pre[i] = pre[i - 1] + (std::abs(nums[i] - nums[i - 1]) <= maxDiff ? 1 : 0);
        }

        std::vector<bool> ans;
        for (auto &query : queries) {
            int u = query[0], v = query[1];

            if (u == v) {
                ans.emplace_back(true);
                continue;
            } 
           
            bool res = pre[v] - pre[u] == v - u;
            ans.emplace_back(res);
        }

        return ans;
    }
};