from typing import *

class Info:
    def __init__(self, x: int = 0, sum: int = 0, cnt: int = 0):
        self.x = x
        self.sum = sum
        self.cnt = cnt

class Solution:
    def sumAndMultiply(self, s: str, queries: List[List[int]]) -> List[int]:
        n, MOD = len(s), int(1e9 + 7)

        pre = [Info() for _ in range(n)]
        pre[0] = Info(int(s[0]), int(s[0]), 1 if s[0] != '0' else 0)
        for i in range(1, n):
            digit = int(s[i])

            if digit == 0:
                pre[i] = pre[i - 1]
                continue

            pre[i].sum = pre[i - 1].sum + digit
            pre[i].cnt = pre[i - 1].cnt + 1
            pre[i].x = (pre[i - 1].x * 10 + digit) % MOD

        pow10 = [0] * (n + 1)
        pow10[0] = 1
        for i in range(1, n + 1):
            pow10[i] = pow10[i - 1] * 10 % MOD

        ans = [0] * len(queries)
        for i, query in enumerate(queries):
            l, r = query[0], query[1]

            if l == 0:
                ans[i] = pre[r].x * pre[r].sum % MOD
                continue

            sum = pre[r].sum - pre[l - 1].sum
            cnt = pre[r].cnt - pre[l - 1].cnt
            x = (pre[r].x - pre[l - 1].x * pow10[cnt] % MOD + MOD) % MOD
            ans[i] = x * sum % MOD

        return ans 

