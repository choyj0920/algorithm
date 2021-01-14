# baek1069 집으로
import sys
import math
input = sys.stdin.readline

x,y,d,t=map(int,input().split())

dis = math.sqrt((x**2)+(y**2))

jump=dis//d
spare=dis-jump*d # 거리를 모자르게 점프 후 남은 거리
result=dis
# 쭉 그냥 간것과 점프해서 간것
result=min(result,spare+jump*t)

# 점프가 1번 이상이면 경로중 최소두개를 같은 만큼 비틀어서 사정권안의 위치를 도달가능
if jump>0: result=min(result,(jump+1)*t*1.0)
else: # 점프 한번의 사정권 이라면
    #점프하고 나서 되돌아와서 도달
    result=min(result,d-spare+t)
    if dis<d: # 2번점프로 바로 도착하기 (경로가 점프한번의 거리가 일치하는경우 제외)
        result=min(result,t*2.0)
        
print(round(result,10))


