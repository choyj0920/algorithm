# baek14425 문자열집합 -trie 풀이 pypy로 제출
import sys
input= sys.stdin.readline

n,m =map(int,input().split())
n_word=["" for _ in range(n)]
m_word=["" for _ in range(m)]
class Node:
    def __init__(self,key):
        self.key=key
        self.child=dict()

class Trie:
    def __init__(self):
        self.head=Node(None)

    def insert(self, word):
        cur =self.head

        for ch in n_word[word]:
            if ch not in cur.child:
                cur.child[ch]=Node(ch)
            cur = cur.child[ch]
        cur.child['*']=True

    def find(self,word):
        
        cur=self.head
        for ch in m_word[word]:
            if ch in cur.child:
                cur=cur.child[ch]
            else:
                return False
        if '*' in cur.child:
            return True
        return False
        
trie=Trie()

for _ in range(n):
    n_word[_]=input()
    trie.insert(_)

cnt=0
for _ in range(m):
    m_word[_]=input()
    if trie.find(_):
        cnt+=1

print(cnt)
