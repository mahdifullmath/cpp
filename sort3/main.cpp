# include <iostream>
using namespace std;
main ()
{
	float n1,n2,n3,t;
	cin>>n1>>n2>>n3;
	if (n3>n2)
	{
		t=n2;
		n2=n3;
		n3=t;
	}
	if (n2>n1)
	{
		t=n2;
		n2=n1;
		n1=t;
	}
	if (n3>n2)
	{
		t=n2;
		n2=n3;
		n3=t;
	}
	cout<<n3<<endl<<n2<<endl<<n1;
	return 0;

}
