# baek10828 스택 
import sys

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
    order = sys.stdin.readline().split()
    if len(order)>1:
        num=int(order[1])
    order=order[0]
    if order =='push':
        stack.push(num)
    elif order=='pop':
        print(stack.pop())
    elif order=='size':
        print(stack.size())
    elif order=='empty':
        print(stack.empty())
    elif order=='top':
        print(stack.top())
        
    
    
