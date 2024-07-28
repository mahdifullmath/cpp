#include <iostream>
using namespace std;

int main()
{
int W[2][2];
int P[3][1];
int D[3][3];
int Display;
{
cin>>W[2][2];
cout<<W[2][2]<<endl;
}
void floyd2(int n,const number W[2][2],int number D[3][3],int index P[3][1])
{
index i,j,k;
for(i=1;i<=n;i++)
for(j=1;j<=n;j++)
p[i][j]=0;
D=W
for(k=1;k<=n;k++)
for(i=1;i<=n;i++)
for(j=1;j<=n;j++)
if(D[i][k]+D[k][j]<D[i][j])
{
P[i][j]=k;
D[i][j]=D[i][k]+D[k][j];
}

return 0;
}
}
