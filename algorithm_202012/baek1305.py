# baek1305 광고

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
lenT=int(input())
T=str(input())

table =makeTable(T)
p_len=lenT-table[lenT-1]

print(p_len)