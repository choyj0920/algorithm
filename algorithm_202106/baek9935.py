# baek9935 문자열 폭발
word = input()    # 전체 문자열
bombword = input()      # 폭발 문자열

lastChar = bombword[-1] # 폭발 문자열의 마지막 글자
stack = []
length = len(bombword)  # 폭발 문자열의 길이

for char in word:
    stack.append(char)
    if char == lastChar and ''.join(stack[-length:]) == bombword:
        del stack[-length:]

answer = ''.join(stack)

if answer == '':
    print("FRULA")
else:
    print(answer)
 
