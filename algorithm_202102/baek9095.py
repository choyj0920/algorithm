# baek9095 1, 2, 3 더하기

dp= [0]*11
dp[0]=1
for _ in range(11):
    temp=dp[_]
    
    if _+1<11:
        dp[_+1] +=temp
    if _+2<11:
        dp[_+2] +=temp
    if _+3<11:
        dp[_+3] +=temp
for _ in range(int(input())):
    print(dp[int(input())])

