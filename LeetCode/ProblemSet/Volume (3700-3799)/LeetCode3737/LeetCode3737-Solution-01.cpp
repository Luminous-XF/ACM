#include <bits/stdc++.h>

class Solution {
public:
    int countMajoritySubarrays(std::vector<int>& nums, int target) {
       const int n = (int) nums.size();
       
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int j = i; j < n; j++) {
                nums[j] == target ? cnt++ : cnt--;
                if (cnt > 0) {
                    ans++;
                }
            }
        }

        return ans;
    }
};