# baek10101 삼각형 외우기
arr = [int(input()) for i in range(3)]
arr.sort()

def solution():
    if sum(arr) != 180:
        print("Error")
        return 
    if arr[2]==60:
        print("Equilateral")
        return
    if arr[0] == arr[1] or arr[1]==arr[2]:
        print("Isosceles")
    else:
        print("Scalene")

solution()