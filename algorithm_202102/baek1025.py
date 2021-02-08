# baek1025 제곱수 찾기
import sys
import math
input=sys.stdin.readline

M, N = map(int, input().split())

numbers = []
for _ in range(M):
    numbers.append(list(map(int, list(input().replace('\n', '')))))

result = -1

for m in range(M): # 행
    for n in range(N): # 열
        for weight_m in range(-M, M): # -M부터 시작
            for weight_n in range(-N, N): # -N부터 시작
                if weight_m == 0 and weight_n == 0: continue # 공차가 0이면 다음 반복으로
                step = 0
                x = m
                y = n
                value = ''
                # 입력받은 수들의 범위 안에서 가능한 수열 추출
                while (0 <= x < M) and (0 <= y < N):
                    # 숫자 조합을 하고
                    value += str(numbers[x][y])
                    step += 1

                    # 제곱수이고, 최댓값 갱신이 가능한지 확인
                    value_int = int(''.join(value))
                    value_sqrt = math.sqrt(value_int)
                    value_decimal = value_sqrt - int(value_sqrt)
                    if value_decimal == 0 and value_int > result: result = value_int

                    x = m + step * weight_m
                    y = n + step * weight_n

print(result)