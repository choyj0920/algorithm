# baek10815 숫자 카드 
import sys
input=sys.stdin.readline
n=int(input())
arr=list(map(int,input().split()))
arr=sorted(arr)
m=int(input())
findlist=list(map(int,input().split()))

def solution(start,end,des):
    if(start>end):
        return 0
    mid= (start+end)//2

    if (arr[mid] < des):
        return solution(mid+1,end,des)
    elif (arr[mid] > des):
        return solution(start,mid-1,des)
    else:
        return 1
for i in findlist:
    print(solution(0,n-1,i),end=" ")
    