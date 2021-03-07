# baek2445 별찍기 -8 
a=int(input())
b=a
for i in range(1,a+1):
    print('*'*(i)+' '*(2*(b-i))+'*'*(i))
for k in range(1,b+1):
    print('*'*(b-k)+' '*(2*k)+'*'*(b-k))