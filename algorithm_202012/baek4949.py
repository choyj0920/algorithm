# baek4949 균형잡힌 세상

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

while True:
    stack=Stack()
    temp=input().rstrip()
    if temp=='.':
        break
    isRight=True
    for i in temp:
        if i=='(':
            stack.push(1)
        elif i==')':
            if stack.pop()!=1:
                isRight=False
                break
        elif i=='[':
            stack.push(2)
        elif i==']':
            if stack.pop() != 2:
                isRight=False
                break
    if isRight and stack.size()==0:
        print("yes")
    else:
        print("no")



