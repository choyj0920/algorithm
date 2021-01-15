# baek1915 가장 큰 정사각형

import sys
input=sys.stdin.readline

n, m = map(int, input().split()) 
table = [list(map(int, list(input().rstrip()))) for _ in range(n)] 
ans = 0 
for i in range(n): 
    for j in range(m): 
        if i>0 and j>0 and table[i][j] == 1: 
            table[i][j] += min(table[i-1][j], table[i][j-1], table[i-1][j-1]) 
        ans = max(ans, table[i][j]) 

print(ans*ans)
