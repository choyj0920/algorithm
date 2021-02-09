# baek10039 평균점수
cnt=0
for _ in range(5):
    temp=int(input())
    cnt+=  temp if temp>40 else 40
print(cnt//5)