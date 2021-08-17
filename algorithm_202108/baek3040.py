# baek3040 백설 공주와 일곱 난쟁이
arr= [int(input()) for i in range(9)]
cnt =sum(arr)
def solution():
    
    for i in range(9):
        num1= cnt -arr[i]
        if cnt <100:
            continue
        
        for j in range(9):
            if i==j :
                continue
            num2 = num1-arr[j]
            if num2==100:
                return [i,j]

ans =solution()
for i in range(9):
    if i not in ans:
        print(arr[i])