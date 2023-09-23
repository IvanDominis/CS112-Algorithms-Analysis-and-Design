/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/
#include <iostream>
#include <vector>
#include <map>
using namespace std;
class Graph 
{
public:
    vector<vector<int> > P;
    map<string ,int> m1;
    int v,e,n;
    string h[1000];
    void nhap(int v1,int e1)
    {
        v=v1;
        e=e1;
        string x,y,z;
        for(int i=0;i<v;i++)
	        {   
            vector<int> v2;
		    for(int j=0;j<v;j++)
			    v2.push_back(0);
		    P.push_back(v2);
	        }
        for(int i=0;i<v;i++)
            {
                cin>>z;
                h[i]=z;
                m1[h[i]]=i;
            }
        for(int i=0;i<e;i++)
            {
            cin>>x>>y;
            P[m1[x]][m1[y]]=1;
            }
        
    }

    void myProcess(int n1)
    {
        n=n1;
        string k[1000]; 
        int a[n],x,y,r=0,f=0;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            if(a[i]==1)
            {
                cin>>k[r]>>k[r+1];
                r+=1;
            }
            else
               cin>>k[r];
            r+=1;
        }
        for(int i=0;i<n;i++)
        {
            x=m1[k[f]];
            y=m1[k[f+1]];
            if(a[i]==1)
            {
                if(P[x][y]==1)
                    cout<<"TRUE";
                else
                    cout<<"FALSE";
                cout<<endl;
                f++;
            }
            else
            {
                int d=0;
                for(int j=0;j<v;j++)
                    if(P[x][j]==1)
                    {
                        cout<<h[j]<<" ";
                        d=1;
                    }
                if(d==0)
                    cout<<"NONE";
                cout<<endl;
            }
            f++;
        }   
    }
};
//###INSERT CODE HERE -

int main()
{
    Graph G;
    int v, e, n; cin >> v >> e >> n;
    G.nhap(v, e);
    G.myProcess(n);
    return 0;
}

