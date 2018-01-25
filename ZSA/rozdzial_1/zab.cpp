#include <bits/stdc++.h>
using namespace std;

int x, y, s;
int res;

int main()
{
	cin>>x>>y>>s;
	res = ceil((double)(y-x)/s);
	cout<<res<<endl;
	return 0;
}
