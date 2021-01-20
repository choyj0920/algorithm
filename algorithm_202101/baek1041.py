# baek1041 주사위

import sys
input=sys.stdin.readline

N = int(input())
dice = list(map(int, input().split()))


if N == 1:
    print(sum(dice)-max(dice))
    
else:
    #1면 최솟값
    min_one = min(dice)
    
    #2면 최솟값
    min_two = sum(dice)
    for i in range(6):
        for j in range(6):
            if i != j and i + j != 5: #반대편
                min_two =  min(min_two, dice[i] + dice[j])
    #3면 최솟값
    min_three = sum(dice)
    for i in [0, 5]:
        for j in [1, 4]:
            for k in [2, 3]:
                min_three = min(min_three, dice[i] + dice[j] + dice[k])
    #밑면
    base_side = 0
    #밑면 꼭지점
    base_side += min_two * 4
    #밑면 변
    base_side += min_one * 4 * (N-2)
    #윗면
    upper_side = 0
    #윗면 꼭지점
    upper_side += min_three * 4
    #윗면 변
    upper_side += min_two * 4 * (N-2)
    #윗면 중앙면
    upper_side += min_one * ((N-2) ** 2)
    #옆면
    side = 0
    #옆면 꼭지점
    side += min_two * 4 * (N-2)
    #옆면 중앙면
    side += min_one * 4 * ((N-2) ** 2)
    
    print(upper_side + side + base_side)


