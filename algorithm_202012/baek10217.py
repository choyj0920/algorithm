# baek10217 KCM Travel

import sys
input =sys.stdin.readline
INF= int(1e9)  #무한을 의미하는 값으로 10억을 설정



T= int(input())
for t in range(T):
    # 공항 수, 지원비용, 티켓정보수
    n, m, k = map(int,input().split())
    edges=[[] for _ in range(n+1)]

    for _ in range(k):
        #  출발, 도착, 비용 소요시간
        u,v,c,d=map(int,input().split()) 
        edges[u].append([v,c,d])

    dp =[[INF for _ in range(m+1)] for _ in range(n+1)] # 열:비용, 행 도착지, dp[][]=소요시간 , 시작점은 1
    dp[1][0]=0 # 1->1로 갔을 때 비용은0 시간도 9

    # 비용 0인거 부터 비용이 m인 것 들 까지
    for fee in range(m+1):
        # 도착지 1~n까지
        for des in range(1,n+1):
            if dp[des][fee] == INF: continue # 해당하는 경로 없음
            time= dp[des][fee] #fee의 비용으로 des까지 갈 때 소요시간 time
            for dv,dc,dd in edges[des]: #des에서 출발하는 경로 반복문 도착,비용 소요시간
                if dc+fee > m : continue # 비용 벗어나면 x
                # 1에서 dv까지 가는 새로운 값과 이전값 비교 시간
                dp[dv][dc+fee]= min(dp[dv][dc+fee],time+dd)

    result=min(dp[n])
    
    if result ==INF:
        print('Poor KCM')
    else:
        print(result)
            

            
        

    