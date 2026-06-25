//
// Created by Luminous on 2026/3/11 23:36
//


#pragma GCC optimize(3)

#include <bits/stdc++.h>

class Solution {
public:
    int maxFreeTime(int eventTime, int k, std::vector<int>& startTime, std::vector<int>& endTime) {
        const int n = (int) startTime.size();

        int freeTime = getLeftFreeTime(0, startTime, endTime);
        int ans = freeTime;
        for (int i = 0; i < n; i++) {
            freeTime += getRightFreeTime(i, n, eventTime, startTime, endTime);

            ans = std::max(ans, freeTime);

            int j = i - k + 1;
            if (j >= 0) {
                freeTime -= getLeftFreeTime(j, startTime, endTime);
            }
        }

        return ans;
    }

    int getLeftFreeTime(int i, std::vector<int>& startTime, std::vector<int>& endTime) {
        return i == 0 ? startTime[i] - 0 : startTime[i] - endTime[i - 1];;
    }

    int getRightFreeTime(int i, int n, int eventTime, std::vector<int>& startTime, std::vector<int>& endTime) {
        return i == n - 1 ? eventTime - endTime[i] : startTime[i + 1] - endTime[i];
    }
};