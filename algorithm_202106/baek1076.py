# baek1076 저항
resistence={"black":0,"brown":1,"red":2,"orange":3,"yellow":4,"green":5,"blue":6,"violet":7,"grey":8,"white":9}
import sys
input=sys.stdin.readline
ans= resistence[input().rstrip()]*10
ans+= resistence[input().rstrip()]
ans*= 10**resistence[input().rstrip()]

print(ans)