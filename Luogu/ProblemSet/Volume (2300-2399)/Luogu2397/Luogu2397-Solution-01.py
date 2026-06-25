import sys


def solve(input):
    n = int(next(input))

    ans, cnt = 0, 0
    for _ in range(0, n):
        v = int(next(input))
        if cnt == 0:
            ans = v
        
        cnt += (1 if ans == v else -1)
    
    print(ans)


if __name__ == "__main__":
    input = iter(sys.stdin.read().strip().split())

    solve(input)