# baek5597 과제 안 내신 분
arr=[0]*31
for i in range(28):
    arr[int(input())]=1
for j in range(1,31):
    if arr[j]==0:
        print(j)