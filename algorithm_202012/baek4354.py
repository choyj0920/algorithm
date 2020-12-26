# baek4354 문자열제곱

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
while True:
    T=str(input())
    if T=='.': break
    lenT=len(T)
    table =makeTable(T)
    p_len=lenT-table[lenT-1]
    if lenT%p_len==0:
        print(lenT//p_len)
    else:
        print(1)
