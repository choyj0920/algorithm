# baek10798
import sys
arr=[]
for i in range(5):
    temp=sys.stdin.readline().rstrip()
    for j in range(len(temp)):
        arr.append([j,i,temp[j]])
arr.sort()
for i in arr:
    print(i[2],end='')
print()