# baek2522 별찍기-12
n = int(input())

for a in range(1, n+1):
    print(('*' * a).rjust(n))

for a in range(n-1, 0, -1):
    print(('*' * a).rjust(n))