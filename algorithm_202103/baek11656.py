# baek11656 접미사 배열
import sys
s=input().rstrip()
arr=[]
for i in range(len(s)):
    arr.append(s[i:])
arr=sorted(arr)
for i in arr:
    print(i)
