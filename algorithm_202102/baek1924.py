# baek1924 2007년

days=[0,31,28,31,30,31,30,31,31,30,31,30,31]
dayofWeek={1:"MON",2:"TUE",3:"WED",4:"THU",5:"FRI",6:"SAT",0:"SUN"}
def solution(month, day):
    cnt=0
    for _ in range(1,month):
        cnt+=days[_]
    
    cnt+=day
    cnt%=7

    print(dayofWeek[cnt])
a,b=map(int,input().split())
solution(a,b)
    
    
    