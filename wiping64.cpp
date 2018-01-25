#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef set<int> SI;

const int INF = 1000000007;
const int MAXN = 3001;
const LL MOD = 1000000007;
const LD eps = 0.00000001;

#define FOR(i, b, e) for(int i = b; i <= e; ++i)
#define FORD(i, b, e) for(int i = b; i >= e; --i)
#define REP(i, n) FOR(i, 0, n-1)
#define REV(i, n) FORD(i, n-1, 0)
#define VAR(v, n) __typeof(n) v = (n)
#define ALL(c) (c).begin(), (c).end()
#define SIZE(c) (int)(c).size()
#define FOREACH(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define PB push_back
#define PP pop_back
#define MP make_pair
#define ST first
#define ND second


bool prime[1000001];
int t[2000][2000];

int main(){

    ios_base::sync_with_stdio(0);

    int n;
    cin>>n;
    n++;

    for (int i=2; i*i<=n; i++){
        if(!prime[i]){
            for (int j = i*i ; j<=n; j+=i)
                prime[j] = 1;
        }
    }
    prime[2]=0;


    for(int i=0; i<2000; i++){
        for(int j=0; j<2000; j++){
            t[i][j]=-1;
        }
    }


    int cnt=2;
    int y=1000,x=1000;
    t[y][x]=0;
    int miny=y,maxy=y,minx=x,maxx=x;

    for(int i=1; cnt<=n; i++){
        for(int j=1; j<=i; j++){
            if(cnt+1>n){
                cnt++;
                break;
            }
            if(i%2==1){
                t[y][++x]=!prime[cnt++];
                //t[y][++x]=cnt++;
            }else{
                t[y][--x]=!prime[cnt++];
                //t[y][--x]=cnt++;
            }
        }
        for(int j=1; j<=i; j++){
            if(cnt+1>n){
                cnt++;
                break;
            }
            if(i%2==1){
                t[--y][x]=!prime[cnt++];
                //t[--y][x]=cnt++;
            }else{
                t[++y][x]=!prime[cnt++];
                //t[++y][x]=cnt++;
            }
        }
        miny=min(miny,y);
        minx=min(minx,x);
        maxy=max(maxy,y);
        maxx=max(maxx,x);
    }
    //cout<<maxx<<" "<<maxy<<" "<<minx<<" "<<miny;

    for(int i=miny; i<=maxy; i++){
        for(int j=minx; j<=maxx; j++){
            if(t[i][j]==-1)
                cout<<" ";
            if(t[i][j]==0)
                cout<<".";
            if(t[i][j]==1)
                cout<<"#";
        }
        cout<<endl;
    }

    return 0;
}
