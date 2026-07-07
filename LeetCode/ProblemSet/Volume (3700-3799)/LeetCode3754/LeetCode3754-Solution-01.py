class Solution:
    def sumAndMultiply(self, n: int) -> int:
        if n == 0:
            return 0
        
        x, sum, k = 0, 0, 1
        while n > 0:
            n, v = divmod(n, 10)

            if v == 0:
                continue

            sum += v
            x += v * k
            k *= 10

        return x * sum 