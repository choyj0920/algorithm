# baek2747 피보나치 수
arr=[0]*46
arr[1]=1
arr[2]=1

def fibo(num):
    if num==0:
        return 0
    elif num ==1:
        return 1
    if arr[num] != 0:
        return arr[num]
    else:
        arr[num] =fibo(num-1)+fibo(num-2)
        return arr[num]

print(fibo(int(input())))