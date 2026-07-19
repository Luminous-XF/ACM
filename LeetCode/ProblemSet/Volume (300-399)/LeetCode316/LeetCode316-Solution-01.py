from typing import *
import bisect

class Solution:
    def removeDuplicateLetters(self, s: str) -> str:
        book = [[] for _ in range(26)]
        for i, c in enumerate(s):
            j = ord(c) - ord('a')
            book[j].append(i)

        length = sum(1 for v in book if len(v) > 0)
        pre = -1
        ans = []
        for _ in range(length):
            for i in range(0, 26):
                if not book[i]:
                    continue

                idx = book[i][bisect.bisect_right(book[i], pre)]
                ok = True
                for j in range(0, 26):
                    if not book[j] or i == j:
                        continue
                    
                    if book[j][-1] < idx:
                        ok = False
                        break

                if ok:
                    ans.append(chr(ord('a') + i))
                    pre = idx
                    book[i] = []
                    break

        return ''.join(ans)