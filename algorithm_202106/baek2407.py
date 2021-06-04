# baek2407 조합
import math

n, m = map(int, input().split())
up = math.factorial(n)
down = (math.factorial(n - m)) * (math.factorial(m))
print(up // down)