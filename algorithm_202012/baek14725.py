# baek14725 개미굴

import sys
input=sys.stdin.readline

N=int(input())
ant=[]
 
for i in range(N):
    arr=list(input().split())
    ant.append(arr[1:])
 
ant.sort()
for i in range(N):
    if i==0:#첫배열
        for j in range(len(ant[i])):
            print("--"*j+ant[i][j])
    else:
        count=-1
        for j in range(len(ant[i])):#dfs
            if len(ant[i-1])<=j or ant[i-1][j]!=ant[i][j]: #이전배열과 같은지 비교
                break
            else:#같다면 출력하지 않고 넘어간다.
                count=j#어디까지 같은지 저장
        for j in range(count+1,len(ant[i])):#같은것을 제외한 나머지 인자 출력
            print("--" * j + ant[i][j])