#include<bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REV(i, n) for(int i = n-1; i >= 0; i--)
#define FOR(i, b, e) for(int i = b; i <= e; i++)
#define FORD(i, b, e) for(int i = b; i >= e; i--)
#define PB push_back
#define ST first
#define ND second
#define MP make_pair
#define INF 1000000001
#define MAXN 10000
using namespace std;

vector<pair<int, int> > g[MAXN];
int n, m;
int dist[MAXN];

struct cmp
{
    bool operator()(const int &a, const int &b)
    {
        return (dist[a] == dist[b] ? a<b : dist[a] < dist[b]);
    }
};

set<int, cmp> kopiec;

void dijkstra(int s)
{
    kopiec.insert(s);

    FOR(i, 1, n)
    dist[i] = INF;

    dist[s] = 0;

    int v;

    while(!kopiec.empty())
    {
        v = *kopiec.begin();
        kopiec.erase(kopiec.begin());
        REP(i, g[v].size())
        {

            if(dist[g[v][i].ST]>dist[v]+g[v][i].ND)
            {
                kopiec.erase(g[v][i].ST);
                dist[g[v][i].ST] = dist[v]+g[v][i].ND;
                kopiec.insert(g[v][i].ST);
            }
        }
    }

}

int main()
{
    int a, b, c;
    cin>>n>>m;
    REP(i, m)
    {
        cin>>a>>b>>c;
        g[a].PB(MP(b, c));
        g[b].PB(MP(a, c));
    }

    dijkstra(1);

    FOR(i, 1, n)
    cout<<i<<" : "<<dist[i]<<endl;

}
