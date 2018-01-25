#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REV(i, n) for(int i = n-1; i >=0; i--)
#define FOR(i, b, e) for(int i = b; i <= e; i++)
#define FORD(i, b, e) for(int i = b; i >= e; i--)
using namespace std;

#define NL 6
#define SP 4


struct Tree
{
    int depth, M;
    int *load, *sub;

    Tree(int d)
    {
        depth = d-1;
        M = 1 << depth+1;
        load = new int[2*M];
        sub = new int[2*M];
        REP(i, 2*M) load[i] = sub[i] = 0;
    }

    ~Tree()
    {
        delete[]load;
        delete[]sub;
    }
    
    void insert(int v, int u, int x, int y, int a, int b)
    {
		if(b < x || y < a) return;
		if(a <= x && y <= b)
		{
			load[u] += v;
			sub[u] += v * (y-x+1);
			return;
		}
		
		int mid = (x+y)/2;
		insert(v, 2*u, x, mid, a, b);
		insert(v, 2*u+1, mid+1, y, a, b);
		sub[u] = sub[2*u] + sub[2*u+1] + load[u] * (y-x+1);
	}

    void insert(int a, int b, int v)
    {
        insert(v, 1, 0, M-1, a, b);
    }
    
    int query(int u, int x, int y, int a, int b)
    {
		if(b < x || y < a) return 0;
		if(a <= x && y <= b)
		{
			return sub[u];
		}
		
		int mid = (x+y)/2;
		return query(2*u, x, mid, a, b) + query(2*u+1, mid+1, y, a, b) + load[u] * (min(b, y) - max(a, x) + 1);
	}
    
    
    int query(int a, int b)
    {
        return query(1, 0, M-1, a, b);
    }

    void Draw()
    {
        system("clear");
        cout<<"\n\t\tDrzewo przedzial - przedzial (+,+) \n\n\n";
                int len = 1, it = 1, xx, xy;



        for(int i = 0; i <= depth+1; i++, len*=2)
        {
            xx = (i==depth+1 ? 0 : NL-1) + ((1<<depth-i)-1)*(NL+SP);
            xy = (1<<(depth+1-i))*(NL+SP)-NL;
            for(int x = 0; x < xx; x++)
                cout<<" ";

            for(int y = 0; y < len; y++)
            {
                cout<<setw(NL)<<load[it++];
                if(y != len-1)
                for(int x = 0; x < xy; x++)
                    cout<<" ";
            }
            cout<<"\n";
            it-=len;

            for(int x = 0; x < xx; x++)
                cout<<" ";

            for(int y = 0; y < len; y++)
            {
                cout<<setw(NL)<<sub[it++];
                if(y != len-1)
                for(int x = 0; x < xy; x++)
                    cout<<" ";
            }
            cout<<"\n\n";
        }

        cout<<"\n\n";
        cout<<"Mozliwe operacje:\n\n";
        cout<<"insert a b v\n";
        cout<<"query a b\n\n";
    }

    void Read()
    {
        string buf;
        cin>>buf;
        int a,b,c;

            if(buf == "insert")
            {
                cin>>a>>b>>c;
                this->insert(a, b, c);
                this->Draw();
                printf("Wstawiono %d na przedziale [%d, %d]\n\n", c, a, b);
            }
            else if(buf=="query")
            {
                cin>>a>>b;
                this->Draw();
                c = this->query(a, b);
                printf("query(%d, %d) = %d\n\n", a, b, c);
            }
    }

};

int main()
{
    Tree drzewo(4);
    drzewo.Draw();
    while(1)
        drzewo.Read();


    return 0;
}
