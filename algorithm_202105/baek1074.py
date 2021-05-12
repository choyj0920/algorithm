# baek1074 Z
import sys

result = 0

def solution(n, x, y):
    global result
    if x == r and y == c:
        print(int(result))
        exit(0)
    if n == 1:
        result += 1
        return

    if not (x <= r < x + n and y <= c < y + n): # r,c가 (x,x+n-1) , (y,y+n-1) 칸에 포함되지 않았으면
        result += n * n
        return
    solution(n / 2, x, y)
    solution(n / 2, x, y + n / 2)
    solution(n / 2, x + n / 2, y)
    solution(n / 2, x + n / 2, y + n / 2)


n, r, c = map(int, sys.stdin.readline().split(' '))
solution(2 ** n, 0, 0)