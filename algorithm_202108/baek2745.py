# baek2745 진법 변환
def to10(c):
    if c.isdigit():
        return int(c)
    else:
        return ord(c)-ord("A")+10

def main():
    N,B =map(str, input().split())
    B= int(B)
    ans=0
    for i in range(len(N)):
        ans+= to10(N[i]) * (B**(len(N)-1-i))

    print(ans)
    
if __name__ == '__main__':
    main()
    