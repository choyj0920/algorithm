# baek11652 카드
card=dict()
for i in range(int(input())):
    n=int(input())
    if n in card:
        card[n] +=1
    else:
        card[n]=1
card =sorted(card,key = lambda x: (-x[1],x[0]))
print(card[0][0])