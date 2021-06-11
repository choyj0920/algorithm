# baek16953 A -> B
import sys
input=sys.stdin.readline

def main():
    a,b =map(int,input().split())

    que=[(a,1)]
    while que:
        cur,cnt=que.pop(0)
        if cur ==b:
            print(cnt)
            return
        num=cur*2
        if num <= b:
            que.append((num,cnt+1))
        num = cur*10+1
        if num <= b:
            que.append((num,cnt+1))
    print(-1)

if __name__ == '__main__':
    main()
    
        
