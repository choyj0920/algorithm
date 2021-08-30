# baek9093 단어 뒤집기

for i in range(int(input())):
    arr=list(map(str,input().split()))
    for j in arr:
        print(j[::-1],end=' ')
    print()
