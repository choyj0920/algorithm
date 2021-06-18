# baek10988 팰린드롬인지 확인하기

def main():
    ss=input().rstrip()
    front,end=0,len(ss)-1
    while front<end:
        if ss[front] != ss[end]:
            print(0)
            return
        
        front +=1
        end -=1
    print(1)
    
if __name__ == '__main__':
    main()
    