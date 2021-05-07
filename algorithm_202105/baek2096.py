# baek2096 내려가기
import sys
input = sys.stdin.readline
n = int(input())
s = [list(map(int, input().split())) for i in range(n)]
lax, cax, rax = s[0][0], s[0][1], s[0][2]
lin, cin, rin = s[0][0], s[0][1], s[0][2]
for i in range(1, n):
     lax, cax, rax = max(lax, cax) + s[i][0], max(lax, cax, rax) + s[i][1], max(cax, rax) + s[i][2]
     lin, cin, rin = min(lin, cin) + s[i][0], min(lin, cin, rin) + s[i][1], min(cin, rin) + s[i][2]
print(max(lax, cax, rax), min(lin, cin, rin))