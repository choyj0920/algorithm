# baek3003 킹, 퀸, 룩, 비숍, 나이트, 폰
arr =list(map(int,input().split()))
correct =[1,1,2,2,2,8]
for i in range(6):
    print(correct[i] -arr[i],end=' ')
