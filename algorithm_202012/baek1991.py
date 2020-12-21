# baek1991 트리순회

import sys
input=sys.stdin.readline

root='A'
nodes={}

n=int(input())

def preorder_print(node):
    print(node, end='')
    if nodes[node][0] is not None: preorder_print(nodes[node][0])
    if nodes[node][1] is not None: preorder_print(nodes[node][1])
    
def inorder_print(node):
    if nodes[node][0] is not None: inorder_print(nodes[node][0])
    print(node,end='')
    if nodes[node][1] is not None: inorder_print(nodes[node][1])

def postorder_print(node):
    if nodes[node][0] is not None: postorder_print(nodes[node][0])
    if nodes[node][1] is not None: postorder_print(nodes[node][1])
    print(node,end='')


for i in range(n):
    temp=input().split()
    if temp[0] not in nodes:
        nodes[temp[0]]=[None,None]
    if temp[1] != ".":
        nodes[temp[0]][0]=temp[1]
    if temp[2] != ".":
        nodes[temp[0]][1]=temp[2]


preorder_print('A')
print()      
inorder_print('A')
print()
postorder_print('A')
print()