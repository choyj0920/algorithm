# baek11655 ROT13
S = str(input())
alphabet = 'abcdefghijklmnopqrstuvwxyz'
ALPHABET = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'

answer = ''
for s in S:
    if s == ' ':
        answer += ' '
        continue
    try:
        answer += str(int(s))
    except:
        if s in alphabet:
            i = alphabet.index(s)
            if i > 12:
                answer += alphabet[i-13]
            else:
                answer += alphabet[i+13]
        else:
            i = ALPHABET.index(s)
            if i > 12:
                answer += ALPHABET[i-13]
            else:
                answer += ALPHABET[i+13]
            
print(answer)

