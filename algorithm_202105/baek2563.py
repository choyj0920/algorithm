# baek2563 색종이
N = int(input())
arr = [[0 for _ in range(101)] for _ in range(101)]

for _ in range(N):
    x, y = map(int, input().split())
    for i in range(x, x+10):
        for j in range(y, y+10):
            arr[i][j] = 1

ans = 0
for i in arr:
    ans += i.count(1)
print(ans)