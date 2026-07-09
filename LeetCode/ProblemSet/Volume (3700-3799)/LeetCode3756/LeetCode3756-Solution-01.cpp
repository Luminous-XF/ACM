#include <bits/stdc++.h>

class Solution {
public:

    static const int MOD = (int) 1e9 + 7;

    struct Info {
        long long x;
        long long sum;
        int cnt;
    }; 

    std::vector<int> sumAndMultiply(std::string s, std::vector<std::vector<int>> &queries) {
        const int n = (int) s.length();

        std::vector<Info> pre(n);

        pre[0] = {s[0] - '0', s[0] - '0', s[0] == '0' ? 0 : 1};
        for (int i = 1; i < n; i++) {
            int digit = s[i] - '0';

            if (digit == 0) {
                pre[i] = pre[i - 1];
                continue;
            }

            pre[i].sum = pre[i - 1].sum + digit;
            pre[i].cnt = pre[i - 1].cnt + 1;
            pre[i].x = (pre[i - 1].x * 10 + digit) % MOD;
        }

        std::vector<int> pow10(n + 1);
        pow10[0] = 1;
        for (int i = 1; i <= n; i++) {
            pow10[i] = pow10[i - 1] * 10LL % MOD;
        }

        std::vector<int> ans;
        for (auto &query : queries) {
            int l = query[0], r = query[1];
            
            if (l == 0) {
                ans.emplace_back(pre[r].x * pre[r].sum % MOD);
                continue;
            } 

            int cnt = pre[r].cnt - pre[l - 1].cnt;
            long long x = (pre[r].x - pre[l - 1].x * pow10[cnt] % MOD + MOD) % MOD;
            long long sum = pre[r].sum - pre[l - 1].sum;
            ans.emplace_back(x * sum % MOD);
        }

        return ans;
    }
};
