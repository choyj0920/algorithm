// baek1450 냅색문제

#include<bits/stdc++.h>
using namespace std;
typedef pair<long long,long long> pi;
map<long long,long long>s1,s2;
vector<pi>st1,st2;
vector<long long>psum;

void process(vector<long long>&a,map<long long,long long>&s){ //(x,합이 x인 부분집합의 개수)를 저장. 
	for(int i=0; i<a.size(); i++){
		vector<pair<long long,long long> >made;
		made.push_back(make_pair(a[i],1));
		for(auto it = s.begin(); it!=s.end(); it++){
			made.push_back(make_pair(it->first+a[i],it->second));
		}
		for(int j=0; j<made.size(); j++) s[made[j].first]+=made[j].second;
	}	
}
long long bsearch(long long finder){ //finder에 대한 upper bound 
	int l = 0;
	int r = st2.size()-1;
	while(l<=r){
		int mid = (l+r)/2;
		if(st2[mid].first<=finder) l = mid+1;
		else r = mid-1;
	}
	l--;
	if(l<0) return 0;
	else return psum[l];
}
int main(){
	long long n,sum;
	cin>>n>>sum;
	vector<long long>arr(n);
	for(int i=0; i<n; i++) cin>>arr[i];
	vector<long long>arr2;
	for(int i=0; i<n/2; i++){
		arr2.push_back(arr.back());
		arr.pop_back();
	}
    
    //s1에는 처음 절반 배열에 대해 (x, 합이 x인 부분집합의 개수) 가 저장됨.
	//s2에는 뒤의 절반 배열에 대해 (x, 합이 x인 부분집합의 개수) 가 저장됨.  
	process(arr,s1);
	process(arr2,s2);
	
	//이분탐색을 위해 배열에 옮겨담는다. 
	long long ret = 0;
	for(auto it = s1.begin(); it!=s1.end(); it++) st1.push_back(pi(it->first,it->second));
	for(auto it = s2.begin(); it!=s2.end(); it++) st2.push_back(pi(it->first,it->second));
	
	for(int i=0; i<st2.size(); i++){
		if(i==0) psum.push_back(st2[i].second);
		else psum.push_back(st2[i].second+psum.back());
	}
	//앞의 원소만 포함하는 경우 + 앞, 뒤의 원소를 전부 포함하는 경우 
	for(int i=0; i<st1.size(); i++){
		if(st1[i].first<=sum) ret+=st1[i].second*(1+bsearch(sum-st1[i].first));
	}
	
	//뒤의 원소만 포함하는 경우의 수  
	for(int i=0; i<st2.size(); i++){
		if(st2[i].first<=sum) ret+=st2[i].second;
	}
	
	//전체 집합 수 + 공집합  
	cout<<ret+1;
}