# baek1748 수 이어 쓰기1
n = input()
n_len = len(n) - 1
n=int(n)
c = 0
i = 0
while i < n_len:
    c += 9 * (10 ** i) * (i + 1)
    i += 1
c += ((n - (10 ** n_len)) + 1) * (n_len + 1)
print(c)