#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef set<int> SI;

const int INF = 1000000007;

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

#define DEBUG(s) s

int z;
double p[3][3];
double a;

const double eps = 0.000000000001;

double func(double x)
{
    return x*x + (x-a)*(x-a) - 1;
}
 
double bisection(double a, double b)
{
    if(func(a) == 0) return a;
    if(func(b) == 0) return b;
 
    double c = a;
    while ((b-a) >= eps)
    {
        // Find middle point
        c = (a+b)/2;
 
        // Check if middle point is root
        if (func(c) == 0.0)
            break;
 
        // Decide the side to repeat the steps
        else if (func(c)*func(a) < 0)
            b = c;
        else
            a = c;
    }
    return c;
}

int main()
{
	ios::sync_with_stdio(0);
	cout<<setprecision(15)<<fixed;
	
	cin>>z;
	FOR(test, 1, z)
	{
		cin>>a;
		if(/*a <= 1.414213*/1)
		{
			//~ cout<<a<<" ";
			double sinx = bisection(0, a/2);
			double cosx = a-sinx;
			//~ cout<<sinx<<" "<<cosx<<endl;
			//~ cout<<sinx+cosx<<"\n";
			p[0][0] = 0;
			p[0][1] = 0;
			p[0][2] = -0.5;
			p[1][0] = -sinx/2;
			p[1][1] = cosx/2;
			p[1][2] = 0; 
			p[2][0] = cosx/2;
			p[2][1] = sinx/2;
			p[2][2] = 0;
		}
		else
		{
			
		}
		cout<<"Case #"<<test<<":\n";
		REP(i, 3) 
		{
			REP(j, 3) cout<<p[i][j]<<" ";
			//~ cout<<(p[i][0]*p[i][0]+p[i][1]*p[i][1]+p[i][2]*p[i][2])<<" ";
			cout<<"\n";
		}
		
	}

	
	return 0;
}

/*
2
1.000000
1.414213

*/

