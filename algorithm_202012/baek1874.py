# baek1874 스택수열

import sys
input=sys.stdin.readline

class Stack:
    def __init__(self):
        self.arr= []

    def push(self,num):
        self.arr.append(num)
    def size(self):
        return len(self.arr)
    def empty(self):
        return 1 if self.size()==0 else 0
    def pop(self):
        if len(self.arr)==0:
            return -1
        else:
            return self.arr.pop()
    def top(self):
        if len(self.arr)==0:
            return -1
        else:
            return self.arr[len(self.arr)-1]

s=Stack()
n=int(input())
arr = [int(input()) for _ in range(n)]
path=[]
check=False
j=1
for i in range(n):
    while j<n+1:
        if len(s.arr)==0 or s.top() != arr[i]:
            s.push(j)
            path.append(0)
            j+=1
        else:
            break
    if s.pop() != arr[i]: check =True
    path.append(1)

if check:
    print("NO")
else:
    for _ in path:
        print("+" if not _ else "-")
    


        



