# baek 9252 LCS2

import sys
input=sys.stdin.readline

s1=[0]+list(input().strip())
s2=[0]+list(input().strip())
len_s1=len(s1)
len_s2=len(s2)

dp= [[""]*len_s2 for _ in range(len_s1)]

for i in range(1,len_s1):
    for j in range(1,len_s2):
        if s1[i]==s2[j]:
            dp[i][j]=dp[i-1][j-1]+s1[i]
        else:
            if len(dp[i][j-1]) <len(dp[i-1][j]):
                dp[i][j]=dp[i-1][j]
            else:
                dp[i][j]=dp[i][j-1]
print(len(dp[len_s1-1][len_s2-1]))
print(dp[len_s1-1][len_s2-1])

            


