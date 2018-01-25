#include<bits/stdc++.h>
using namespace std;

#define FOR(i, b, e) for(int i = b; i <= e; ++i)

double calka(double(*fun)(double), double a, double b, const int n)
{
	const double h = (a+b) / (double)(2*n);
	double res = fun(a) + fun(b);
	FOR(i, 1, 2*n-1)
	{
		if(i%2==0)
		{
			res+=2*fun(a+i*h);
		}
		else
		{
			res+=4*fun(a+i*h);
		}
	}
	res*=(h/3.0D);
	return res;
}

/*funkcje*/
double f(double x)
{
	return 2*x*x;
}

double g(double x)
{
	return -2*x*x + 5;
}

double fsq(double x)
{
	return f(x)-g(x);
}

double f_g(double x)
{
	return f(x)*f(x);
}



int main()
{
	ios::sync_with_stdio(0);
	int a, b, n;
	cout<<"[a, b] n\n";
	cin>>a>>b>>n;
	cout<<"calka f(x) w przedziale ["<<a<<", "<<b<<"] = "<<calka(f, a, b, n)<<"\n";
	cout<<"calka (f(x) - g(x)) w przedziale ["<<a<<", "<<b<<"] = "<<calka(f_g, a, b, n)<<"\n";
	cout<<"calka PI*f^2(x) w przedziale ["<<a<<", "<<b<<"] = "<<M_PI*calka(fsq, a, b, n)<<"\n";
	return 0;
}
