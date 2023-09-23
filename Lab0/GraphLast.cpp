#include <iostream>
#include <cstring>
#include <map>
using namespace std;
int check(char t1[],char x,int v)
{
    for(int i=0;i<v;i++)
        if(x==t1[i])
            return 1;
    return 0;
}
int main()
{
    int e,n,v=0;
    map <char,int> m1;
    cin>>e>>n;
    char t[e][2],t1[1000];
    for(int i=0;i<e;i++)
    {
        cin>>t[i][0]>>t[i][1];
        if(check(t1,t[i][0],v)==0)
            {   
                t1[v]=t[i][0];
                v+=1;
            }
        if(check(t1,t[i][1],v)==0)
            {   
                t1[v]=t[i][1];
                v+=1;
            }
    }
    for (int i=0;i<v;i++)
        m1[t1[i]]=i;
    bool **G;
    G =new bool*[v];
	for(int i=0;i<v;i++)
		G[i]= new bool[v]; 	
	for(int i=0;i<v;i++)
		for(int j=0;j<v;j++)
			G[i][j]=0; 
    int x,y;
    for(int i=0;i<e;i++)
	{
        x=m1[t[i][0]];
        y=m1[t[i][1]];
		G[x][y]=1;
	}
    char k[n][3];
        int a[n];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            if(a[i]==1)
                cin>>k[i][0]>>k[i][1];
            else
                cin>>k[i][0];
        }
        for(int i=0;i<n;i++)
        {
            x=m1[k[i][0]];
            y=m1[k[i][1]];
            if(a[i]==1)
            {
                if(G[x][y]==1)
                    cout<<"TRUE";
                else
                    cout<<"FALSE";
                cout<<endl;
            }
            else
            {
                int d=0;
                if(check(t1,k[i][0],v)==0)
                    cout<<0<<endl;
                else
                {
                for(int j=0;j<v;j++)
                    if(G[x][m1[t1[j]]]==1)
                        d++;
                cout<<d<<endl;
                }
            }
        }
}