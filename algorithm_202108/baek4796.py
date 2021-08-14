# baek4796 캠핑
l,p,v=map(int,input().split())
cnt=1
while l!=0 or p!=0 or v != 0:
    ans= (v//p) *l
    ans+=min(v%p,l)
    print("Case ",cnt,": ",ans ,sep='')
    cnt+=1

    l,p,v=map(int,input().split())
