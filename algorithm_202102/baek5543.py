# baek5543 상근날드

cnt=2000
drink=2000

for _ in range(3):
    cnt=min(cnt,int(input()))
for _ in range(2):
    drink=min(drink,int(input()))
print(cnt+drink-50)