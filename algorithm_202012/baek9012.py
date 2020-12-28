# baek9012 괄호
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

T= int(input())
while T>0:
    stack=Stack()
    temp=input().rstrip()
    isRight=True
    for i in temp:
        if i=='(':
            stack.push(1)
        elif i==')':
            if stack.pop()==-1:
                isRight=False
                break
    if isRight and stack.size()==0:
        print("YES")
    else:
        print("NO")

    T-=1


