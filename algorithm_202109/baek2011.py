# baek2011 암호코드
import sys

N = sys.stdin.readline().strip()
if N[0] == '0': # 0으로 시작하는 경우
    sys.stdout.write("0")
    exit()

res = [1, 1] # 길이가 0일때 경우의 수 1, 길이가 1일때 경우의 수 1
mod = 1000000

for idx in range(1, len(N)):
    cnt = 0
    num = int(N[idx-1:idx+1])
    
    if int(N[idx]) > 0:
        cnt += res[-1]
    if num >= 10 and num <= 26:
        cnt += res[-2]
    res.append(cnt % mod)

sys.stdout.write(str(res[-1]))
 