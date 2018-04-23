#include <bits/stdc++.h>
using namespace std;

int stokrotki [1001][1001];
int suma [1001][1001];
int x, y, l, p1, p2;

int main()
{
	ios::sync_with_stdio(0);
	
	cin>>l;
	
	for(int k=1;i<=l;i++)
	{

		cin>>x>>y;

		for(int i=0;i<x;i++)
		for(int j=0;j<y;j++) cin>>stokrotki[i][j];
		
		for(int i=0;i<x;i++)
		{
			if(i-1<0)
			p1=0;
			else
			p1=i-1;

			for(int j=0;j<y;j++)
			{

				if(j-1<0)
				p2=0;
				else
				p2=j-1;

				suma[i][j]=max((suma[p1][j]+stokrotki[i][j]),(suma[i][p2]+stokrotki[i][j]));

			}
		}
		cout<<suma[x-1][y-1]<<"\n";

		for(int i=0;i<x;i++)
		for(int j=0;j<y;j++) suma[i][j]=0;


	}
}
