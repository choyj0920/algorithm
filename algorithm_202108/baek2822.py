# baek2822 점수 계산
arr= []
for i in range(1,9):
    arr.append([i,int(input())])
arr= sorted(arr,key= lambda x :(-x[1]))
ans=[x[0] for x in arr[:5]]
ans.sort()
print(sum([x[1] for x in arr[:5]]))
print(*ans)