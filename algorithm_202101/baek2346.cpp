// baek2346 풍선 터뜨리기
#include<iostream>
#include<vector>
using namespace std;
int main(){
    int N;
    cin >> N; // 풍선의 개수
    vector<pair<int,int>> v; // N 개의 요소를 갖는 벡터를생성
    
    for(int i=1;i<=N;i++){ // 풍선 번호는 1부터 N까지  
        int num;
        cin >> num;
        
        v.push_back(make_pair(i,num));
//        v[i].first=i; v[i].second=num;// 다음과 같은 형태로 배열에 선언하면 코드가 작동되지 않는다!        
    }    
    while(v.empty()!=true){ //비어있지 않은 경우에 계속 반복 
        
        cout << v.front().first << " ";
        int a=v.front().second;
        v.erase(v.begin());
        
        
        if (a<0){ //음수 라면 - 맨 뒤를 맨 앞으로 
            for(int j=0;j<abs(a);j++){
                v.insert(v.begin(),v.back());
                v.erase(v.end());
            } 
        }
        else{ // 양수 라면- 맨 앞을 맨 뒤로 
            for(int j=0;j<a-1;j++){
                v.push_back(v.front());
                v.erase(v.begin());
            }
        }
    }
    

    return 0;
}
