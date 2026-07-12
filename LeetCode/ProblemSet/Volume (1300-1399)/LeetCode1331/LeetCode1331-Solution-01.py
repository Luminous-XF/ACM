from typing import *

class Solution:
    def arrayRankTransform(self, arr: List[int]) -> List[int]:
        book = {v: i for i, v in enumerate(sorted(set(arr)), 1)}
        return [book[v] for v in arr]