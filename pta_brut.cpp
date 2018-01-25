#include<bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef set<int> SI;

#define FOR(i, b, e) for(int i = b; i <= e; i++)
#define FORD(i, b, e) for(int i = b; i >= e; i--)
#define REP(i, n) FOR(i, 0, n-1)
#define REV(i, n) FORD(i, n-1, 0)
#define VAR(v, n) __typeof(n) v = (n)
#define FOREACH(i, c) for(VAR(i, (c).begin()); i != (c).end(); i++)
#define PB push_back
#define PP pop_back
#define MP make_pair
#define ST first
#define ND second
#define INF 1000000001
#define MAXN 1000001
#define MAXQ 25

int n, k, q;

int td[MAXN], tk[MAXQ];
int DP[MAXQ][MAXN];

int main()
{
    ios::sync_with_stdio(0);
    cin>>n;

    FOR(i, 1, n)
    cin>>td[i];

    cin>>q;
    REP(i, q)
    cin>>tk[i];

    //wypelnienie tablicy
    REP(i, q)
    FOR(j, 1, n)
    DP[i][j] = INF;


    //DP
    REP(x, q)
    {
        DP[x][1] = 0;
        FOR(i, 2, n)
        {
            FOR(j, max(i-tk[x], 1), i-1)if(j > 0)
                DP[x][i] = min(DP[x][i], DP[x][j] + (td[i] >= td[j] ? 1 : 0));
        }

        //FOR(i, 1, n)
        //cout<<DP[x][i]<<" ";
        //cout<<endl;

        cout<<DP[x][n]<<endl;
    }

    return 0;
}
