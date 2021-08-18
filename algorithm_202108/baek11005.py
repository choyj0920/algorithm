# baek11005 진법 변환2
system = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ" 
N, B = map(int, input().split())
answer = ''

while N != 0:
    answer += str(system[N % B]) #위치로 진법 변환
    N //= B
    
print(answer[::-1])