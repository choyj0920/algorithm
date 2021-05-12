# baek17626 Four Squares
import sys
num = int(sys.stdin.readline().strip())
root = int(num**0.5)
# O(N)
num_list = [i**2 for i in range(root+1)]
# O(N^2)
square_list = [i**2 + j ** 2 for i in range(root+1) for j in range(i, root+1)]

def decide(num):
    if num in num_list:
        return 1
    elif num in square_list:
        return 2
    else:
        # O(N^2)
        for i in num_list:
            if num-i in square_list:
                return 3
        return 4
print(decide(num))