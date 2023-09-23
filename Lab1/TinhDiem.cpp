#include <iostream>
using namespace std;
void input(int a[],int n,float &avap)
{
    for(int i=0;i<n;i++)
        cin>>a[i];
    cin>>avap;
}
float find(float avap,int n,int a[])
{
    float d=avap;
    for(int i=n-1;i>0;i--)
        d=d-10*a[i]/100;
    return d/a[0]*100-0.25;
}
void backtracking(int a[],int n,int avap,float *r[],int d,int f,float sum,int i)
{
    for(float j=0.25;j<=10;j+=0.25)
    {
        r[d][i]=j;
        sum+=r[d][i]*a[i];
        if(i<n && sum<=avap)
            backtracking(a,n,avap,r,d,f,sum,i+1);
        else if(i==n-1)
            backtracking(a,n,avap,r,d+1,f,0,0);
        else
            return;
    }
}
int main()
{
    int n,d=0;
    cin>>n;
    float avap,**rs=new float*[n];
    int a[n];
    input(a,n,avap);
    float f= find(avap,n,a),r[3];
    cout<<f<<endl;
    backtracking(a,n,avap,rs,d,f,0,0);
    for(int i=0;i<d;i++)
        {
            for(int j=0;j<n;j++)
                cout<<rs[i][j]<<" ";
            cout<<endl;
        }
}