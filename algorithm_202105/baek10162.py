# baek10162 전자 레인지
T=int(input())
if T%10==0:
    print(T//300,T%300//60,T%60//10)
else:
    print(-1)
