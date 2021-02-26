# baek10799 쇠막대기
import sys
stack=[]
ss=sys.stdin.readline().strip()
i=0
cnt=0
while i < len(ss):
    if ss[i:i+2] == "()" :
        cnt+=len(stack)

        i+=2
    elif ss[i]=="(":
        stack.append(1)
        i+=1
    elif ss[i]==")":
        i+=1
        cnt+=1
        stack.pop()
print(cnt)

        
        
        
