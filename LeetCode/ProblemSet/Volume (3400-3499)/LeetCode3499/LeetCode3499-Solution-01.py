from typing import *
from math import inf
from itertools import groupby

class Solution:
    def maxActiveSectionsAfterTrade(self, s: str) -> int:
        pre, maxEx, total = -inf, 0, 0
        for c, group in groupby(s):
            cnt = len(list(group)) 
            if c == '1':
                total = total + cnt
            else:
                maxEx = max(maxEx, pre + cnt)
                pre = cnt
        
        return total + maxEx