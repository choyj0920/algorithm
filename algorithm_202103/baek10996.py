# baek10996 별찍기 -21
N = int(input())
even = N//2
odd = N - N//2

for i in range(N):
    print("* " * odd)
    print(" *" * even)
    