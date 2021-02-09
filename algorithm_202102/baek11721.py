# baek11721 열 개씩 끊어 출력하기

ss=input().rstrip()
while (ss!=""):
    print(ss[:10])
    ss=ss[10:]