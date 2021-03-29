# baek5585 거스름돈
arr=[500,100,50,10,5,1]
a=1000-int(input())
cnt=0
for i in arr:
    cnt+=a//i
    a %=i
print(cnt)