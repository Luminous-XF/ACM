from typing import *

class Solution:
    def sequentialDigits(self, low: int, high: int) -> List[int]:
        ans = []
        for i in range(1, 10):
            res = 0
            for j in range(i, 10):
                res = res * 10 + j
                if low <= res <= high:
                    ans.append(res)

        ans.sort()

        return ans