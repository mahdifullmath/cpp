#include <iostream>
#include <stdio.h>
using namespace std;
int finds (char a[],char b[],int j);
int main ()
{
	int m,n,t=0;
	cin>>m;
	cin>>n;
	char a[100];
	char b[100];
	cin.get(a,m);
	cin.get(b,n);
	int i;
	for (i=0;a[i]!=0;i++)
	{
		if (a[i]==b[0])
		{
			t=finds(a,b,i);
			if (t==1)
			break;
		}
	}
		if (t==1)
		cout<<"String starts at : ("<<i<<")";
		else
		cout<<"String not found!";
		return 0;
}
	//**********************************
int finds (char a[],char b[],int j)
	{
		for (int i=0;b[i]!=0;i++)
		{
			if (a[j]!=b[i])
		 	return 0;
			j++;
		}
		return 1;
	}
