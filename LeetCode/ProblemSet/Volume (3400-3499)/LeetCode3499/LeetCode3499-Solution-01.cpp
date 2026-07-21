#include <bits/stdc++.h>

class Solution {
public:
    int maxActiveSectionsAfterTrade(std::string s) {     
        int pre = INT_MIN, cnt = 0, maxEx = 0, total = 0;
        for (int i = 0; i < s.length(); i++) {
            cnt++;
            if (i == s.length() - 1 || s[i] != s[i + 1]) {
                if (s[i] == '1') {
                    total += cnt; 
                } else {
                    maxEx = std::max(maxEx, pre + cnt);
                    pre = cnt;
                }
                cnt = 0;
            }
        }

        return total + maxEx;
    }
};