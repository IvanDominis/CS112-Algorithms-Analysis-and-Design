/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/
#include<iostream>
#include<vector>
using namespace std;

//###INSERT CODE HERE -
void inputGraph(vector<vector<int> > &G,int v,int e)
{
	for(int i=0;i<v;i++)
	{   vector<int> v1;
		for(int j=0;j<v;j++)
			v1.push_back(0);
		G.push_back(v1);
	}
	int x,y;
	for(int i=0;i<e;i++)
	{
		cin>>x>>y;
		G[x-1][y-1]=1;
	}
}
void process(vector<vector<int> > &G,int v,int n)
{
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
int main()
{

	int v, e, n;
	cin >> v >> e >> n; //v: số đỉnh, e: số cạnh, n: số thao tác
	vector<vector<int> > G;
	inputGraph(G,v,e);
    process(G,v,n);
	return 0;
}

