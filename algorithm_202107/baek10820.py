# baek10820 문자열 분석

def fun(s):
    lower,upper,num,blank=0,0,0,0
    for i in s:
        if i.isupper():
            upper +=1
        elif i.islower():
            lower += 1
        elif i==' ':
            blank+=1
        else:
            num += 1
    print(lower,upper,num,blank)
    

while 1:
    try:
        ins=input()
    
        ans = fun(ins)
        
    except EOFError:
        break