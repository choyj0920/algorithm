# baek2169 로봇 조종하기
n, m = map(int, input().split())
mat = [list(map(int, input().split())) for _ in range(n)]

dp = [[-1000000000] * m for _ in range(n)]
left = [[-1000000000] * m for _ in range(n)]
right= [[-1000000000] * m for _ in range(n)]

#1 첫줄작업
dp[0][0] = mat[0][0]
for j in range(1, m):
    dp[0][j] = dp[0][j-1] + mat[0][j]

for i in range(1, n):
    # 2 왼->오
    left[i][0] = dp[i-1][0] + mat[i][0] # 좌에서 우로 가기만 하면 가장 왼쪽칸의 값은 위에칸+현재칸이다.
    for j in range(1, m): 
        left[i][j] = max(dp[i-1][j]+mat[i][j], left[i][j-1]+mat[i][j]) # 좌측칸에서 오는것, 위의칸에서 오는거 중 큰값 선택
    # 3 오 ->왼
    right[i][m-1] = dp[i-1][m-1] + mat[i][m-1] # 우에서 좌로 가기만 하면 가장 우측 칸의 값은 위에칸+ 현재칸
    for j in range(m-2, -1, -1):
        right[i][j] = max(dp[i-1][j] + mat[i][j], right[i][j+1] + mat[i][j]) # 우측 칸에서 오는 것, 위의칸에서 오는 것 중 큰 값 선택
    #4 merge
    for j in range(m):
        dp[i][j] = max(right[i][j], left[i][j]) # left,right 중 큰값 설정

print(dp[n-1][m-1])