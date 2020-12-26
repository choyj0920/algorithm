# baek5670 휴대폰자판
import sys
input= sys.stdin.readline


n_word=[]
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
        cnt=0
        cur=self.head
        for ch in n_word[word]:
            cur=cur.child[ch]
            if len(cur.child)>1 or '*'in cur.child:
                cnt+=1
            
        return cnt



while True:
    try: n=int(input())
    except: break

    trie=Trie()
    cnt=0
    n_word=[]

    for _ in range(n):
        n_word.append(input().rstrip())
        trie.insert(_)
        
    for _ in range(n):
        cnt += trie.find(_)
    print("%.2f"%(cnt/n))


                