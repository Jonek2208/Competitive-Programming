/*Drzewo przedzialowe z macierzami*/
#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int, int> PII;
typedef vector<int> VI;

const int MAXN = 200001;
const int INF = 1e9+7;
const int M = 1 << 18;

#define FOR(i, b, e) for(int i = b; i <= e; ++i)
#define FORD(i, b, e) for(int i = b; i >= e; --i)
#define REP(i, n) FOR(i, 0, n-1)
#define REV(i, n) FORD(i, n-1, 0)
#define PB push_back
#define PP pop_back
#define MP make_pair
#define ST first
#define ND second
#define ALL(c) (c).begin(), (c).end()
#define SIZE(c) (int)(c).size()

#define DEBUG(s) 

int n, q;

int tab[MAXN];
char c;
int a, b;

struct Matrix
{
	int M[5][5];
	
	Matrix()
	{
		FOR(i, 0, 4)
		FOR(j, 0, 4)
		M[i][j] = INF;
		FOR(i, 0, 4) M[i][i] = 0;
	}
	
	Matrix operator+(const Matrix &b) const
	{
		Matrix c;
		
		FOR(i, 0, 4)
		FOR(j, 0, 4)
		{
			c.M[i][j] = INF;
			FOR(k, i, j) 
			{
				c.M[i][j] = min(c.M[i][j], M[i][k] + b.M[k][j]);
			}
		}
		return c;
	}
};

ostream & operator<<(ostream &a, Matrix & b)
{
	FOR(i, 0, 4)
	{
		FOR(j, 0, 4)
		{
			if(b.M[i][j] == INF) a<<"- ";
			else a<<b.M[i][j]<<" ";
		}
		a<<"\n";
	}
	return a;
}

Matrix val[10];

void valinit()
{
	val[2].M[0][0] = 1; 
	val[2].M[0][1] = 0; 
	val[0].M[1][1] = 1; 
	val[0].M[1][2] = 0; 
	val[1].M[2][2] = 1; 
	val[1].M[2][3] = 0; 
	val[7].M[3][3] = 1; 
	val[7].M[3][4] = 0; 
	val[6].M[4][4] = 1; 
	val[6].M[3][3] = 1; 
}

Matrix Tree[2*M];

void init()
{
	FOR(i, 1, n)
	{
		Tree[i+M] = val[tab[i]];
	}
	
	FORD(i, M-1, 1) Tree[i] = Tree[2*i] + Tree[2*i+1];
}

Matrix query(int a, int b, int x, int y, int u)
{
	if(y < a || b < x)
	{
		return Matrix();
	}
	
	if(a <= x && y <= b) return Tree[u];
	
	int d = (x+y)/2;
	return query(a, b, x, d, 2*u) + query(a, b, d+1, y, 2*u+1);
}

Matrix query(int a, int b)
{
	return query(a, b, 0, M-1, 1);
}


int main()
{
	ios::sync_with_stdio(0);
	cin>>n>>q;
	FOR(i, 1, n)
	{
		cin>>c;
		tab[i] = (int)c - '0';
	}
	valinit();
	init();
	
	DEBUG
	(
	FOR(i, 1, 2*M-1) cout<<"T : "<<i<<endl<<Tree[i]<<endl;
	
	FOR(x, 0, 9)
	{
		cout<<"val["<<x<<"]\n";
		cout<<val[x]<<endl;
	}
	
	FOR(i, 1, n) cout<<tab[i]<<" "; cout<<endl;
	)
	
	
	while(q--)
	{
		cin>>a>>b;
		Matrix wyn = query(a, b); 
		DEBUG(cout<<wyn<<endl;)
		cout<<(wyn.M[0][4] == INF ? -1 : wyn.M[0][4])<<"\n";
	}
	
	return 0;
}

/*

in:

8 3
20166766
1 8
1 7
2 8

out:

4
3
-1

in:

15 5
012016662091670
3 4
1 14
4 15
1 13
10 15

out:

-1
2
1
-1
-1

in:

4 2
1234
2 4
1 2

out:

-1
-1

*/
