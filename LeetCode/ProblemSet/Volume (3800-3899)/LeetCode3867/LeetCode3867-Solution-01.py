from typing import *
from math import gcd

class Solution:
    def gcdSum(self, nums: list[int]) -> int:
        n, maxNum = len(nums), 0
        for i, num in enumerate(nums):
            maxNum = max(maxNum, num)
            nums[i] = gcd(maxNum, num)

        nums.sort()

        return sum(gcd(nums[i], nums[n - i - 1]) for i in range(0, n // 2))