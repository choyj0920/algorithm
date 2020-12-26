# baek1786 찾기
import sys
# readline 쓰면 뒤에 엔터 떼줘야 해서 기본 input 사용

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
T=str(input())
P=str(input())
lenT=len(T)
lenP=len(P)
# 테이블
table=makeTable(P)
answer=[]

# KMP 구문
j =0
for i in range(lenT):           # T 문장 처음부터 끝까지 비교
    while j>0 and T[i] != P[j]: # 앞에 한자리 이상 같고 이번자리가 다를 떄
        j= table[j-1]           # j를 0에서 겹치는 부분만큼 jump해서 다시 비교
    if T[i] == P[j]:        # 일치하면
        if j== lenP-1:      # P와 전부 일치하면 
            j= table[j]     # 다음 체크에 Jump
            answer.append(i-lenP+2) # 값 기록
        else:
            j+=1
# 출력
print(len(answer))
print(*answer)

            
