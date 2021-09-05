# baek1357 뒤집힌 덧셈
a,b=map(str, input().split())
a= int(a[-1::-1])
b= int(b[-1::-1])
ans=str(a+b)
ans= int(ans[-1::-1])
print(ans)

