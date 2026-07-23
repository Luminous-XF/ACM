#include <bits/stdc++.h>

class Solution {
public:
    int uniqueXorTriplets(std::vector<int>& nums) {
        const int n = (int) nums.size();

        return n <= 2 ? n : 1 << std::bit_width(size_t(n));
    }
};