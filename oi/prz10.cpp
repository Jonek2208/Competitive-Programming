/*Przemytnicy X OI*/
#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;

const int INF = 1e9+7;
const int MAXN = 5002;

#define FOR(i, b, e) for(int i = b; i <= e; ++i)
#define FORD(i, b, e) for(int i = b; i >= e; --i)
#define REP(i, n) FOR(i, 0, n-1)
#define REV(i, n) FOR(i, n-1, 0)
#define PB push_back
#define PP pop_back
#define MP make_pair
#define ST first
#define ND second
#define ALL(c) (c).begin(), (c).end()
#define SIZE(c) (int)(c).size()

#define DEBUG(s) s

int n, m, a, b, c;

int koszt[MAXN];
vector<PII> g[MAXN];
vector<PII> gt[MAXN];
int dist[MAXN];
bool odw[MAXN];
priority_queue<PII> heap;

void dijkstra(int s, vector<PII> * graf)
{
	FOR(i, 1, n) dist[i] = INF;
	FOR(i, 1, n) odw[i] = 0;
	dist[s] = 0;
	heap.push(MP(0, s));
	
	while(!heap.empty())
	{
		int v = heap.top().ND;
		heap.pop();
		if(!odw[v])
		{
			odw[v] = true;
			for(auto w: graf[v])
			{
				dist[w.ST] = min(dist[w.ST], dist[v] + w.ND);
				heap.push(MP(-dist[w.ST], w.ST));
			}
		}
	}
	
	FOR(i, 1, n) koszt[i] += dist[i];
}


int main()
{
	ios::sync_with_stdio(0);
	cin>>n;
	
	FOR(i, 1, n) cin>>koszt[i];
	FOR(i, 1, n) koszt[i] /= 2;
	
	cin>>m;
	
	REP(i, m)
	{
		cin>>a>>b>>c;
		g[a].PB(MP(b, c));
		gt[b].PB(MP(a, c));
	}
	
	dijkstra(1, g);
	dijkstra(1, gt);
	
	
	int res = INF;
	
	FOR(i, 1, n)
	{
		res = min(res, koszt[i]);
	}
	cout<<res<<"\n";

	return 0;
}
/*
4
200
100
40
2
6
1 2 10
1 3 5
2 1 25
3 2 10
3 4 5
4 1 50
*/
