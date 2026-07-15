#include <bits/stdc++.h>

class Solution {
public:
    long long gcdSum(std::vector<int>& nums) {
        const int n = (int) nums.size();

        int maxNum = 0;
        for (int i = 0; i < n; i++) {
            maxNum = std::max(maxNum, nums[i]);
            nums[i] = std::gcd(nums[i], maxNum);
        }

        std::ranges::sort(nums);

        long long sum = 0;
        int i = 0, j = n - 1;
        while (i < j) {
            sum += std::gcd(nums[i], nums[j]);
            i++, j--;
        }

        return sum;
    }
};