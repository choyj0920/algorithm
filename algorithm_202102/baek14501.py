# baek14501 퇴사
n = int(input()) 
data = [tuple(map(int, input().split())) for _ in range(n)] 
charge = list(map(lambda x: x[1], data)) 

for i in range(n): 
    if i + data[i][0] > n: # 퇴사 전까지 마무리 할 수 없으면 
        charge[i] = 0  # 어차피 상담할 수 없으므로 비용을 0으로 설정
        continue 
    t = charge[i] 
    for j in range(i + data[i][0], n): 
        if t + data[j][1] > charge[j]: 
            charge[j] = t + data[j][1] 

print(max(charge))
