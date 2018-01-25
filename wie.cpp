#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
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
#define MAXN 200000

int n, wynik, mb, poprz, mx_lng;
int tab[MAXN], rmc[MAXN], lng[MAXN], res[MAXN], unt[MAXN];
PII srt[MAXN];

map<int, set<PII> > op;

//int maksymalny()
//{
	//int y;
	
	//int poc, kon, sr;
	
	
	
	
	//return y;
//}






int main()
{
	ios::sync_with_stdio(0);
	cin>>n;
	
	REP(i, n)
	{
		cin>>tab[i];
		srt[i] = MP(tab[i], i);
	}
	
	//sortowanie + wskazniki
	
	sort(srt, srt + n);
	
	REP(i, n)
	rmc[srt[i].ND] = i;
	
	//REP(i, n)
	//cout<<tab[i]<<" "<<rmc[i]<<endl;
	
	//najdluzsze ciagi z punktu
	REP(i, n)
	{
		if(i==0 || rmc[i] < rmc[i-1])
		{
			int k = 1;
			
			while(rmc[i + k] > rmc[i + k - 1]) k++;
			
			lng[i] = k;
			unt[i] = 1;
			
		}
		else
		{
			lng[i] = lng[i-1] - 1;
			unt[i] = unt[i-1] + 1;
		}
		
		mx_lng = max(lng[i], mx_lng);
	}
	


	//cout<<"Longest"<<endl;
	//REP(i, n)
	//cout<<lng[i]<<" "<<unt[i]<<endl;
	
	//REP(i, n)
	//op[lng[i]].insert(MP(i, tab[i]));
	
	
	//FOREACH(it, op)
	//{
		//cout<<it->ST<<" : ";
		//FOREACH(itt, it->ND)
		//cout<<itt->ST<<"|"<<itt->ND<<" ";
		//cout<<endl;
		
	//}
	

	
	
	//brutalny maks
	FORD(i, n-2, 0)
	{
			int mx = 0;

			FOR(j, i + 1, n-1)
			{
				if(rmc[j] > rmc[i])
				mx = max(mx, lng[j]);
			}
			
			res[i] = unt[i] + mx;
	}
	
	REP(i, n)
	wynik = max(wynik, res[i]);
	

	
	
	////brut
	
	//FOR(k, 0, n-1)
	//FOR(j, k, n-1)
	//{
		//mb = 1;
		//poprz = 0;
		//FOR(i, 1, n-1)
		//{	
			//if(tab[i] > tab[poprz])
			//mb++;
			//else mb = 1;
			
			//poprz = i;
			//wynik = max(wynik, mb);
			
			//if(i == k - 1) i = j;
			
			
			////cout<<k<<" "<<j<<" "<<" "<<i<<" "<<wynik<<" "<<mb<<endl;
		//}
	//}
	
	cout<<wynik;
	
	
	return 0;
}

/*
	10
	1 4 5 2 7 6 8 9 8 3
	
	9
	5 3 4 9 2 8 6 7 1

 */

