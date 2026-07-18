#include <bits/stdc++.h>

class Solution {
public:
    int findGCD(std::vector<int>& nums) {
        auto [a, b] = std::ranges::minmax(nums);
        return std::gcd(a, b);
    }
};