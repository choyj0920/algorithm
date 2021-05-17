# baek21740 도도의 수학놀이
from functools import cmp_to_key
import sys
input = sys.stdin.readline

def cmp(s1, s2): # 우위 비교
	a, b = s1+s2, s2+s1
	return 1 if a>b else 0 if a==b else -1
	
def cmp2(s1, s2): # 두배 할 수 비교
	la, lb = len(s1), len(s2)
	if la==lb:
		a, b = int(s1), int(s2)
		return 1 if a>b else 0 if a==b else -1
	return 1 if la>lb else 0 if la==lb else -1
	
convert = {"0":"0", "1":"1", "2":"2", "5":"5", "6":"9","8":"8","9":"6"}

def revS(n): #
	ss = ''
	for i in n[::-1]:
		ss += convert[i]
	return ss

N = int(input())
arr = input().split()

a = [revS(x) for x in arr]
a.sort(key=cmp_to_key(cmp2))
a += [a[-1]]
a.sort(key=cmp_to_key(cmp))

ans = ""
for i in a:
	ans += revS(i)
print(ans)