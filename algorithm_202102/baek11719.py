# baek11719 그대로 출력하기2
while True:
    try:
        print(input())
    except EOFError:
        break