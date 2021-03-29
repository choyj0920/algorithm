# baek10808 알파벳 개수
arr=[0]*26
ss=input()
for i in ss:
    arr[ord(i)-ord('a')]+=1

print(*arr)