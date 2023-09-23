#include<iostream>
using namespace std;

void inputGraph(bool*G[], int e)
{	 	
	int u,y;
	for(int i=0;i<e;i++)
	{
		cin>>u>>y;
		G[u-1][y-1]=1;
        G[y-1][u-1]=1;
	}
}
int main()
{
	int v, e, n;
	cin >> v >> e >> n;
	bool **G; 
	G =new bool*[v];
	for(int i=0;i<v;i++)
		G[i]= new bool[v]; 	
	for(int i=0;i<v;i++)
		for(int j=0;j<v;j++)
			G[i][j]=0; 
	inputGraph(G,e);
	int t[n][3];
	for(int i=0;i<n;i++)
	{
		cin>>t[i][0];
		if(t[i][0]==1)
			cin>>t[i][1]>>t[i][2];
		else	
			cin>>t[i][1];
	}
	for(int i=0;i<n;i++)
	{
		int x=t[i][1]-1,y=t[i][2]-1;
		if(t[i][0]==1)
		{
			if(G[x][y]==1)
				cout<<"TRUE";
			else	
				cout<<"FALSE";
		}
		else
		{
			int d=0;
			for(int i=0;i<v;i++)
				if(G[x][i]==1)
				{
					cout<<i+1<<" ";
					d=1;
				}
			if(d==0)
				cout<<"NONE";
		}	
		cout<<endl;
	}
}