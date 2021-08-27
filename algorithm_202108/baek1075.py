# baek1075 나누기
n=int(input().rstrip()[:-2]+'00')
f=int(input())

print(format(f-n%f,'02'))