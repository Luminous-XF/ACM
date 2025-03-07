//
// Created by Luminous on 2025/3/7 22:41
//

#pragma GCC optimize(3)

#include <bits/stdc++.h>


class Solution {
public:
    int beautifulSubsets(std::vector<int>& nums, int k) {
        std::unordered_map<int, int> book;

        int ans = 0;
        dfs(0, ans, k, nums, book);

        return ans;
    }

    void dfs(int step, int &ans, int k, std::vector<int> &nums, std::unordered_map<int, int> &book) {
        if (step == nums.size()) {
            ans++;
            return;
        }

        dfs(step + 1, ans, k, nums, book);

        int x = nums[step];
        if (book[x - k] == 0 && book[x + k] == 0) {
            book[x]++;
            dfs(step + 1, ans, k, nums, book);
            book[x]--;
        }
    }
};