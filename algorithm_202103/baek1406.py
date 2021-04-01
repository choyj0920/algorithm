# baek1406 에디터
import sys
input=sys.stdin.readline

ans=list(map(str,input().rstrip()))
stack=[]

for i in range(int(input())):
    command=input().split()
    if command[0]== 'P':
        ans.append(command[1])
        
    elif command[0]=="B":
        if(len(ans)==0):
            continue
        ans.pop()

    elif command[0]=="L":
        if(len(ans)==0):
            continue
        stack.append(ans.pop())
    else:
        if(len(stack)==0):
            continue
        ans.append(stack.pop())
while len(stack) >0:
    ans.append(stack.pop())
    
for c in ans:
    print(c,end="")
    
        
    
