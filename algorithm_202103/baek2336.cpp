#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#include <string>
#include <stack>

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int INF = 987654321;
const int mod = 1e9 + 7;

struct test{
    int x,y,z;

    test(int _x =0,int _y = 0,int _z = 0) : x(_x),y(_y),z(_z)
    {}

    bool operator<(const test& rhs)
    {
        return x < rhs.x;
    }
};

int n;
vector<test> vec;
vector<int> segtree;

int update(int newidx,int k,int idx,int s,int e)
{

    if(!(s <= newidx && newidx <= e)) return INF;

    if(s == e) return segtree[idx] = k;

    int m = (s+e)/2;
    update(newidx,k,2*idx,s,m);
    update(newidx,k,2*idx+1,m+1,e);

    return segtree[idx] = min(segtree[2*idx],segtree[2*idx+1]);
}

int get(int qs,int qe,int idx,int s,int e)
{
    if(qe < s || e < qs) return INF;

    if(qs <= s && e <= qe) return segtree[idx];

    int m = (s+e)/2;

    return min(get(qs,qe,2*idx,s,m),get(qs,qe,2*idx+1,m+1,e));
}

int main(int argc, char** argv) {
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin>>n;
    vec = vector<test>(n);
    segtree = vector<int>(4*n,INF);
    for(int j = 0;j<3;j++)
    {
        for(int i = 0;i<n;i++)
        {
            int stu;
            cin>>stu;
            stu--;

            if(j == 0)
            {
                vec[stu].x = i;
            }
            if(j == 1)
            {
                vec[stu].y = i;
            }
            if(j == 2)
            {
                vec[stu].z = i;
            }
        }
    }

    sort(vec.begin(),vec.end());

    int ans = 1;
    update(vec[0].y,vec[0].z,1,0,n-1);

    for(int i = 1;i<n;i++)
    {
        int minz = get(0,vec[i].y,1,0,n-1);

        //cout<<minz<<" "<<vec[i].z<<endl;

        if(minz > vec[i].z)
        {

            ans++;
        }

        update(vec[i].y,vec[i].z,1,0,n-1);
    }

    cout<<ans;
    return 0;
}