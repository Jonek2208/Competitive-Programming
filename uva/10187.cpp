#include<bits/stdc++.h>
using namespace std;

const int INF = 1000000001;
const int MAXN = 101;

typedef long long LL;
typedef unsigned int UI;
typedef pair<int, int> PII;
typedef vector<int> VI;

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

int n, m, z;

unordered_map <string, int> mapa;

VI g[MAXN]; 

void BFS()
{
	REP(i, kol.size())
	{
		int x = kol[i].ST, y = kol[i].ND;
		
		if(x>=1 && y>=1 && x<=n && y<=m) 
		{
			FOR(xx, -1, 1)
			FOR(yy, -1, 1)
			{
				if((xx*xx + yy*yy == 1))
				{
					if(!odw[x+xx][y+yy])
					{
						odw[x+xx][y+yy] = true;
						w[x+xx][y+yy] = w[x][y] + 1;
						kol.PB(MP(x+xx, y+yy));
					}
				}
			}
		}
		
	}
	
}



int main()
{
	string buf;
	cin>>z;
	while(z--)
	{
		cin>>n>>m;
		FOR(i, 1, n)
		{
			cin>>buf;
			REP(j, buf.length())
			mp[i][j+1] = buf[j] - '0';
		}
		
		init();
		BFS();
		
		FOR(i, 1, n)
		{
			FOR(j, 1, m)
			cout<<w[i][j]<<" ";
			cout<<endl;
		}
	}	
	return 0;
}




