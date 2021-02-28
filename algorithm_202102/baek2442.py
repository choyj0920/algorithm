# baek2442 별찍기-5

n = int(input())

for a in range(1, n+1):
    print(' ' * (n-a) + '*' * (2*a-1))