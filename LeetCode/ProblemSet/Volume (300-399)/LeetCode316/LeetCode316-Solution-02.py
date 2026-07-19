from typing import *
from collections import Counter

class Solution:
    def removeDuplicateLetters(self, s: str) -> str:
        cnt = Counter(s)
        book = set()
        ans = []

        for c in s:
            cnt[c] -= 1

            if c in book:
                continue

            while ans and c < ans[-1] and cnt[ans[-1]] > 0:
                book.remove(ans[-1])
                ans.pop()

            book.add(c)
            ans.append(c)

        return ''.join(ans)