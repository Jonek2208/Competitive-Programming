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

    void insert(int a, int b, int v)
    {
        int l = M + a;
        int r = M + b;
        int length = 1;

        load[l]+=v;
        sub[l]+=v;

        if(r!=l)
        {
            load[r]+=v;
            sub[r]+=v;
        }

        while(l >= 1)
        {
            if(l < r-1)
            {
                if(l%2 == 0)
                {
                    load[l+1] += v;
                    sub[l+1] += v * length;
                }
                if(r%2 == 1)
                {
                    load[r-1] += v;
                    sub[r-1] += v * length;
                }
            }

            if(r<M)
            {
                sub[l] = sub[2*l] + sub[2*l + 1] + load[l] * length;
                sub[r] = sub[2*r] + sub[2*r + 1] + load[r] * length;
                //~ sub[l] = max(sub[2*l], sub[2*l + 1]) + load[l];
                //~ sub[r] = max(sub[2*r], sub[2*r + 1]) + load[r];
            }

            l/=2;
            r/=2;
            length*=2;

        }
    }

    int query(int a, int b)
    {
        int l = M + a;
        int r = M + b;
        int length = 1, llen = 1, rlen = (r!=l ? 1 : 0), res = 0, maxl = 0, maxr = 0;

        while(l >= 1)
        {
            res += llen * load[l] + rlen * load[r];
            //~ maxl += load[l];
            //~ maxr += load[r];

            if(l < r-1)
            {
                if(l%2 == 0)
                {
                    res += sub[l+1];
                    llen+=length;
                    //~ maxl = max(maxl, sub[l+1]);
                }
                if(r%2 == 1)
                {
                    res += sub[r-1];
                    rlen+=length;
                    //~ maxr = max(maxr, sub[r-1]);
                }
            }

            l/=2;
            r/=2;
            length*=2;
        }
        //~ res = max(maxl, maxr);
        return res;
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
/*
int load[2*M], sub[2*M];

void insert(int a, int b, int v)
{
    int l = M + a;
    int r = M + b;
    int length = 1;

    load[l]+=v;
    sub[l]+=v;

    if(r!=l)
    {
        load[r]+=v;
        sub[r]+=v;
    }

    while(l >= 1)
    {
        if(l < r-1)
        {
            if(l%2 == 0)
            {
                load[l+1] += v;
                sub[l+1] += v * length;
            }
            if(r%2 == 1)
            {
                load[r-1] += v;
                sub[r-1] += v * length;
            }
        }

        if(r<M)
        {
            sub[l] = sub[2*l] + sub[2*l + 1] + load[l] * length;
            sub[r] = sub[2*r] + sub[2*r + 1] + load[r] * length;
        }

        l/=2;
        r/=2;
        length*=2;

    }
}

int query(int a, int b)
{
    int l = M + a;
    int r = M + b;
    int length = 1, llen = 1, rlen = (r!=l ? 1 : 0), res = 0;

    while(l >= 1)
    {
        res += llen * load[l] + rlen * load[r];

        if(l < r-1)
        {
            if(l%2 == 0)
            {
                res += sub[l+1];
                llen+=length;
            }
            if(r%2 == 1)
            {
                res += sub[r-1];
                rlen+=length;
            }
        }

        l/=2;
        r/=2;
        length*=2;
    }
    return res;
}
*/
int main()
{
    /*
       int w1, w2, w3, w4;

       while(1)
       {
           cin>>w1;
           if(w1)
           {
               cin>>w2>>w3>>w4;
               insert(w2,w3,w4);
               printf("wstawiono %d na przedziale <%d, %d> \n", w4, w2, w3);
           }
           else
           {

               for(int i = 0; i < M; i++)
                   cout<<load[i]<<" "<<sub[i]<<endl;
               /*cin>>w2>>w3;
               w4 = query(w2,w3);
               printf("suma na przedziale <%d, %d> = %d \n", w2, w3, w4);
           }
       }*/

    Tree drzewo(4);
    drzewo.Draw();
    while(1)
        drzewo.Read();


    return 0;
}
