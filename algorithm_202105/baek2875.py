# baek2875 대회 or 인턴
n, m, k = map(int, input().split())
cnt = 0
while n + m >= k and n >= 0 and m >= 0:
    n -= 2
    m -= 1
    cnt += 1
print(cnt - 1)