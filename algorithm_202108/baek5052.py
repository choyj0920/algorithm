# baek5052 전화번호
import sys
input=sys.stdin.readline
def solution(numbers):
    numbers.sort() 
    for i in range(len(numbers)-1): 
        if numbers[i] == numbers[i+1][:len(numbers[i])]: 
            return False
    return True

numbers=[]
for i in range(int(input())):
    n=int(input())
    for _ in range(n):
        numbers.append(input().strip())
    print( "YES" if solution(numbers) else "NO")
    numbers.clear()
