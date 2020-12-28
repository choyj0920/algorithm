# baek10773 제로
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
    
stack=Stack()
n=int(input())
for _ in range(n):
    order=int(input())
    if order==0:
        stack.pop()
    else:
        stack.push(order)
    
cnt=0
for _ in stack.arr:
    cnt+=_
print(cnt)
    
    
