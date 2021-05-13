# baek10610 30
n=list(input().rstrip())
n.sort(reverse=True)
hap=0
for i in n:
    hap+=int(i)
if hap%3 ==0:
    if '0' in n:
        for i in n:
            print(i,end='')
        print()
    else:
        print(-1)
else:
    print(-1)
