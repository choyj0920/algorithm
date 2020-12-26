# baek14425 문자열집합
import sys
input= sys.stdin.readline

class Node:
    def __init__(self,key):
        self.key=key
        self.child=dict()

class Trie:
    def __init__(self):
        self.head=Node(None)

    def insert(self, word):
        cur =self.head

        for ch in word:
            if ch not in cur.child:
                cur.child[ch]=Node(ch)
            cur = cur.child[ch]
        cur.child['*']=True

def print_trie(l,cur):
    if '*' in cur.child:
        return
    sorted_child=sorted(cur.child)
    
    for c in sorted_child:
        print("--"*l, end='')
        print(c)
        print_trie(l+1,cur.child[c])
    
trie=Trie()

for _ in range(int(input())):
    foods = input().split()
    k= int(foods.pop(0))

    trie.insert(foods)

cur =trie.head
print_trie(0,cur)
