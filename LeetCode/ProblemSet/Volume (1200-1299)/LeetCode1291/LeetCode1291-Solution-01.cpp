#include <bits/stdc++.h>

class Solution {
public:
    std::vector<int> sequentialDigits(int low, int high) {
        std::vector<int> ans;
        for (int i = 1; i < 10; i++) {
            int res = 0;
            for (int j = i; j < 10; j++) {
                res = res * 10 + j;
                if (low <= res && res <= high) {
                    ans.emplace_back(res);
                }
            }
        }

        std::ranges::sort(ans);

        return ans;
    }
};