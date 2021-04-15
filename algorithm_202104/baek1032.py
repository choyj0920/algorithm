# baek1032 명령 프롬프트
import sys
input=sys.stdin.readline
N=int(input())
filenames=[]
for i in range(N):
    filenames.append(input().rstrip())
ans=""
for a in range(len(filenames[0])):
    check=True
    aa=filenames[0][a]
    for i in range(1,N):
        if aa != filenames[i][a]:
            check=False
            break

    if check:
        ans+=aa
    else:
        ans+="?"
        
print(ans)