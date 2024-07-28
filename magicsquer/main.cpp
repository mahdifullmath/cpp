#include <iostream>
using namespace std;
int main(){
	int n,k;
	cin>>n>>k;
	int m[n][n];
	m [n][n]={{0,0}};
    for (int i=0; i<n;i++)
	{
        for (int j=0;j<n;j++)
		{
			cout<<m[i][j]<<" ";
		}
		cout<<endl;
	}

/*	for (int i=n/2,j=0,z=k;z<k+n*n-1; )
	{
		if (m[i][j]!=0)
	  	j++;
    	if (j<0)
  		j=n;
		if (i>n)
  		i=0;
		m[i][j]=z;
		i++;
		j--;
		z++;
	}
	for (int i=0; i<n;i++)
	{
		for (int j=0;j<n;j++)
		{
			cout <<m[i][j]<<" ";
		}
		cout<<endl;
	}*/
	return 0;
}
