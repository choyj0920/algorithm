# baek1016 제곱 ㄴㄴ수

import sys
import math
input=sys.stdin.readline
minimum,maximum= map(int,input().split())
ans=maximum-minimum+1
arr=[False]*(maximum-minimum+2)

i=2

while i**2<=maximum:
    
    sNum = minimum//(i**2)
    if minimum % (i**2) !=0: # 이 제곱수로 안나눠지면
        sNum+=1
    while sNum*(i**2) <= maximum :
        if arr[sNum*(i**2)-minimum]==False:
            arr[sNum*(i**2)-minimum]=True
            ans-=1
        sNum+=1
    i+=1

print(ans)
            


