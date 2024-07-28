#include <iostream>
#include <stdio.h>
using namespace std;
int main ()
{
	char a[1000];
	cin.get(a,1000);
	int b[3],d;
	cin>>d;
	b[2]=d%10;
	d=d/10;
	b[1]=d%10;
	b[0]=d/10;
	for (int i=0;a[i]!=0;i++)
	{
		if (a[i]<58&&a[i]>48)
		{
			a[i]=a[i]+b[2];
			if (a[i]>57)
			a[i]=a[i]-9;
		}
		else if (a[i]>=97&&a[i]<123)
		{
			a[i]=a[i]+b[1];
			if (a[i]>122)
			a[i]=a[i]-26;
		}
		else if (a[i]>=65&&a[i]<91)
		{
			a[i]=a[i]+b[0];
			if (a[i]>90)
			a[i]=a[i]-26;
		}
	}
	puts(a);
	return 0;
}
