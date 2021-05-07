# baek1550 16진수
import sys
input=sys.stdin.readline
s=input().rstrip()

# 사실이 한줄이라는 ...
# print(int("0x"+input().rstrip(),16))

hexadeci=dict()
for i in range(10):
    hexadeci[str(i)]=i

for i in range(ord('A'),ord('F')+1):
    hexadeci[chr(i)]=10+int(i-ord('A'))
ans=0
for i in range(len(s)):
    temp=hexadeci[s[len(s)-1-i]]
    ans += (16**i) *temp
print(ans)