# baek1259 팰린드롬수
import sys
r=sys.stdin.readline

def check_Palindrome(a):
    front,end=0,len(a)-1
    
    while front<end:
        if a[front]!=a[end]:
            return False
        front+=1
        end-=1
    return True
s=r().strip()
while s!='0':
    print("yes" if check_Palindrome(s) else "no")
    s=r().strip()