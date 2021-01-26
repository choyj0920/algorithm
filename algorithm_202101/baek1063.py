# baek1063 킹

import sys
input=sys.stdin.readline

posKing=[0,0]
posStone=[0,0]

initpos= input().split()
posKing=[ord(initpos[0][0])-ord('A'), int(initpos[0][1])-1]
posStone=[ord(initpos[1][0])-ord('A'), int(initpos[1][1])-1]
n=int(initpos[2])
for i in range(n):
    x,y=0,0
    for _ in input():
        if _=='R':
            x += 1
        elif _ =='L':
            x -= 1
        elif _ =='B':
            y -= 1
        elif _ =='T':
            y += 1
    if 0<=posKing[0]+x<8 and 0<=posKing[1]+y<8:
        pass
    else:
        continue

    if posKing[0]+x==posStone[0] and posKing[1]+y ==posStone[1]:
        if 0<=posStone[0]+x<8 and 0<=posStone[1]+y<8:
            posKing[0] += x
            posKing[1] += y
            posStone[0] += x
            posStone[1] += y
        else:
            continue
    else:
        posKing[0] += x
        posKing[1] += y
print(chr(posKing[0]+ord('A')),posKing[1]+1,sep='')
print(chr(posStone[0]+ord('A')),posStone[1]+1,sep='')


