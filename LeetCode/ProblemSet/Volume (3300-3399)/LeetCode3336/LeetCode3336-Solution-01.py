from typing import *
from math import gcd
from functools import cache

class Solution:
    def subsequencePairCount(self, nums: List[int]) -> int:
        MOD = 1_000_000_007

        @cache
        def dfs(i, j, k) -> int:
            if i < 0:
                return 1 if j == k else 0
            
            return (dfs(i - 1, j, k) + dfs(i - 1, gcd(j, nums[i]), k) + dfs(i - 1, j, gcd(k, nums[i]))) % MOD
        
        return (dfs(len(nums) - 1, 0, 0) - 1) % MOD