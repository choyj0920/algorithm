# baek10819 차이를 최대로
from itertools import permutations
N = int(input())
## 이런 함수가 있데여~
nums = permutations(list(map(int, input().split()))) 

ans = 0

for i in nums:
    sum = 0
    for j in range(N-1):
        sum += abs(i[j] - i[j+1])
    ans = max(ans, sum)
print(ans)