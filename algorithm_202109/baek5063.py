# baek5063 TGN 
for i in range(int(input())):
    a,b,c =map(int,input().split())
    b= b-c
    if a==b:
        print("does not matter")
    elif a<b:
        print("advertise")
    else:
        print("do not advertise")