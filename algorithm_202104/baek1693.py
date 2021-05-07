# baek1693 트리 색칠하기

import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**6)
n = int(input())
s = [[] for i in range(n + 1)]
dp = [[0] * 17 for i in range(n + 1)]
visit = [False for i in range(n + 1)]
def dfs(idx):
    for i in s[idx]:
        if visit[i]:
            continue
        visit[i] = True
        dfs(i)
        for j in range(1, 17):
            m_num = 100000000
            for k in range(1, 17):
                if j != k: 
                    if m_num > dp[i][k]:  # 이전 노드 색중에 가장 비용이 적은 것
                        m_num = dp[i][k] 
            dp[idx][j] += m_num # idx 색에 따른 지정
    for i in range(1, 17):  # 자기 자신 색칠하는 비용
        dp[idx][i] += i
    return

for i in range(n - 1):
    a, b = map(int, input().split())
    s[a].append(b)
    s[b].append(a)
visit[1] = True
dfs(1)
print(min(dp[1][1:]))