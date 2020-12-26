# baek266 시계사진들
import sys
input=sys.stdin.readline

def makeTable(pattern):  # 접두 접미 겹치는거 찾는 함수
    patternSize=len(pattern)
    table = [0  for _ in range(patternSize)]
    j=0
    for i in range(1,patternSize):  # 
        while j>0 and pattern[i] != pattern[j]:
            j=table[j-1]
        if pattern[i]==pattern[j]:
            j+=1
            table[i]= j
    return table

# input
n=int(input())
T=[0]*360000
P=[0]*360000 
for i in map(int,input().split()):
    T[i]=1
for i in map(int,input().split()):
    P[i]=1  
T+=T
lenT=len(T)
lenP=len(P)
# 테이블
table=makeTable(P)

# KMP 구문
check=False
j =0
for i in range(lenT):           # T 문장 처음부터 끝까지 비교
    while j>0 and T[i] != P[j]: # 앞에 한자리 이상 같고 이번자리가 다를 떄
        j= table[j-1]           # j를 0에서 겹치는 부분만큼 jump해서 다시 비교
    if T[i] == P[j]:        # 일치하면
        if j== lenP-1:      # P와 전부 일치하면 
            check=True
            break
        else:
            j+=1
# 출력
print("" if check else 'im',"possible",sep='')
