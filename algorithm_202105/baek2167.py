# baek2167 2차원 배열 합
import sys
input = sys.stdin.readline

h, w = map(int, input().split())
arr = []
for i in range(h):
    arr.append(list(map(int, input().split())))

dp = [[0 for _ in range(w + 1)] for _ in range(h + 1)]
for i in range(1, h + 1):
    for j in range(1, w + 1):
        dp[i][j] = arr[i - 1][j - 1] + dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1]

k = int(input())
for _ in range(k):
    i, j, y, x = map(int, input().split())
    ans = dp[y][x] - dp[y][j - 1] - dp[i - 1][x] + dp[i - 1][j - 1]
    print(ans)