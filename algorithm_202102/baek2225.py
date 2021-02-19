# baek2225 합분해-
n, k = map(int, input().split())
s = [[0] * 201 for i in range(201)]
for i in range(201):
    s[i][1] = 1
for i in range(1, 201):  # 포함된 정수 갯수
    for j in range(201): # 합
        for l in range(j + 1):
            s[j][i] += s[l][i - 1]
print(s[n][k] % 1000000000)
