from typing import *
from itertools import *

class Solution:
    def pathExistenceQueries(self, n: int, nums: List[int], maxDiff: int, queries: List[List[int]]) -> List[bool]:
        pre = list(accumulate((y - x <= maxDiff for x, y in pairwise(nums)), initial=0))
        return [pre[v] - pre[u] == v - u for u, v in queries]
