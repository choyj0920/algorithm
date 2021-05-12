# baek5525 IOIOI 

N = int(input())
M = int(input())
ss = input()
index = 1
answer = 0
cnt = 0
while index < M-1:
    if ss[index-1] == 'I' and ss[index] == 'O' and ss[index+1] == 'I':
        cnt += 1
        if cnt == N:
            answer += 1
            cnt -= 1
        index += 1
    else:
        cnt = 0
    index += 1
print(answer)